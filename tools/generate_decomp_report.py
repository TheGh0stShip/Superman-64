#!/usr/bin/env python3
"""Generate the objdiff v2 progress report consumed by ByteMatch."""

from __future__ import annotations

import csv
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MANIFEST = ROOT / "config/us/matching_units.tsv"
CATALOGUE = ROOT / "config/us/functions.tsv"
NONFUNCTION = ROOT / "config/us/nonfunction_ranges.tsv"
OUTPUT = ROOT / "build/report.json"

CODE_ROM_START = 0x1000
CODE_ROM_END = 0xD49B0
CODE_VRAM_START = 0x80000400


def measures(total_code: int, matched_code: int, total_functions: int,
             matched_functions: int, total_units: int,
             complete_units: int) -> dict[str, object]:
    code_percent = matched_code * 100.0 / total_code if total_code else 0.0
    function_percent = (
        matched_functions * 100.0 / total_functions if total_functions else 0.0
    )
    return {
        "fuzzy_match_percent": code_percent,
        "total_code": str(total_code),
        "matched_code": str(matched_code),
        "matched_code_percent": code_percent,
        "total_data": "0",
        "matched_data": "0",
        "matched_data_percent": 0.0,
        "total_functions": total_functions,
        "matched_functions": matched_functions,
        "matched_functions_percent": function_percent,
        "complete_code": str(matched_code),
        "complete_code_percent": code_percent,
        "complete_data": "0",
        "complete_data_percent": 0.0,
        "total_units": total_units,
        "complete_units": complete_units,
    }


def read_catalogue() -> list[dict[str, object]]:
    rows: list[dict[str, object]] = []
    with CATALOGUE.open(newline="") as stream:
        lines = (line for line in stream if line.strip() and not line.startswith("#"))
        reader = csv.DictReader(
            lines, delimiter="\t", fieldnames=("rom", "size", "vram", "name", "evidence")
        )
        for row in reader:
            start = int(row["rom"], 0)
            size = int(row["size"], 0)
            vram = int(row["vram"], 0)
            if not (CODE_ROM_START <= start < start + size <= CODE_ROM_END):
                raise ValueError(f"catalogue range outside code image: {row['name']}")
            if vram != CODE_VRAM_START + start - CODE_ROM_START:
                raise ValueError(f"catalogue ROM/VRAM mismatch: {row['name']}")
            rows.append({**row, "start": start, "size_int": size, "vram_int": vram})

    rows.sort(key=lambda item: int(item["start"]))
    cursor = CODE_ROM_START
    for row in rows:
        if int(row["start"]) < cursor:
            raise ValueError(f"catalogue overlap before {row['name']}")
        cursor = int(row["start"]) + int(row["size_int"])
    return rows


def read_nonfunction_ranges() -> list[dict[str, int | str]]:
    rows: list[dict[str, int | str]] = []
    with NONFUNCTION.open(newline="") as stream:
        lines = (line for line in stream if line.strip() and not line.startswith("#"))
        reader = csv.DictReader(
            lines, delimiter="\t", fieldnames=("rom", "size", "vram", "kind")
        )
        for row in reader:
            start = int(row["rom"], 0)
            size = int(row["size"], 0)
            vram = int(row["vram"], 0)
            if vram != CODE_VRAM_START + start - CODE_ROM_START:
                raise ValueError("nonfunction ROM/VRAM mismatch")
            rows.append({"start": start, "size": size, "kind": row["kind"]})
    return rows


def validate_image_coverage(catalogue: list[dict[str, object]],
                            nonfunction: list[dict[str, int | str]]) -> None:
    ranges = [
        (int(row["start"]), int(row["size_int"]), "function") for row in catalogue
    ] + [
        (int(row["start"]), int(row["size"]), str(row["kind"]))
        for row in nonfunction
    ]
    cursor = CODE_ROM_START
    for start, size, kind in sorted(ranges):
        if start != cursor:
            raise ValueError(f"program-image gap or overlap before {kind} at {start:#x}")
        cursor += size
    if cursor != CODE_ROM_END:
        raise ValueError("ledgers do not cover the complete program image")


def read_manifest(catalogue: list[dict[str, object]]) -> list[dict[str, object]]:
    rows: list[dict[str, object]] = []
    with MANIFEST.open(newline="") as stream:
        lines = (line for line in stream if line.strip() and not line.startswith("#"))
        reader = csv.DictReader(
            lines,
            delimiter="\t",
            fieldnames=("rom", "size", "vram", "name", "source", "sha256"),
        )
        for row in reader:
            start = int(row["rom"], 0)
            size = int(row["size"], 0)
            vram = int(row["vram"], 0)
            source = ROOT / row["source"]
            if not source.is_file():
                raise ValueError(f"missing matching source: {row['source']}")
            digest = hashlib.sha256(source.read_bytes()).hexdigest()
            if digest != row["sha256"]:
                raise ValueError(f"source hash changed: {row['source']}")
            if not (CODE_ROM_START <= start < start + size <= CODE_ROM_END):
                raise ValueError(f"matching range outside code image: {row['name']}")
            expected_vram = CODE_VRAM_START + start - CODE_ROM_START
            if vram != expected_vram:
                raise ValueError(f"ROM/VRAM mismatch: {row['name']}")
            rows.append({**row, "start": start, "size_int": size, "vram_int": vram})

    rows.sort(key=lambda item: int(item["start"]))
    cursor = CODE_ROM_START
    names: set[str] = set()
    for row in rows:
        start = int(row["start"])
        if start < cursor:
            raise ValueError(f"overlapping matching range: {row['name']}")
        cursor = start + int(row["size_int"])
        name = str(row["name"])
        if name in names:
            raise ValueError(f"duplicate matching function: {name}")
        names.add(name)
    catalogue_by_start = {int(row["start"]): row for row in catalogue}
    for row in rows:
        canonical = catalogue_by_start.get(int(row["start"]))
        if canonical is None:
            raise ValueError("matching manifest contains a non-canonical function start")
        if (int(row["size_int"]) != int(canonical["size_int"])
                or row["name"] != canonical["name"]):
            raise ValueError(f"matching range differs from function body: {row['name']}")
    if len(rows) > len(catalogue):
        raise ValueError("matching function count exceeds the reviewed catalogue")
    return rows


def index_assembly_sources() -> dict[str, str]:
    """Map generated assembly symbols to their source files."""
    symbols: dict[str, str] = {}
    label = re.compile(
        r"(?m)^(?:glabel\s+([A-Za-z_.$][\w.$]*)|([A-Za-z_.$][\w.$]*):)"
    )
    for source in sorted((ROOT / "asm").rglob("*.s")):
        relative = source.relative_to(ROOT).as_posix()
        for match in label.finditer(source.read_text(errors="replace")):
            name = match.group(1) or match.group(2)
            # Later split files are the active source when an older aggregate
            # assembly file still contains the same label.
            symbols[name] = relative
    return symbols


def build_report() -> dict[str, object]:
    catalogue = read_catalogue()
    validate_image_coverage(catalogue, read_nonfunction_ranges())
    rows = read_manifest(catalogue)
    matched_by_start = {int(row["start"]): row for row in rows}
    assembly_sources = index_assembly_sources()
    total_code = sum(int(row["size_int"]) for row in catalogue)
    matched_code = sum(int(row["size_int"]) for row in rows)
    matched_functions = len(rows)
    grouped: dict[str, list[dict[str, object]]] = {}
    for function in catalogue:
        start = int(function["start"])
        size = int(function["size_int"])
        vram = int(function["vram_int"])
        name = str(function["name"])
        matched = matched_by_start.get(start)
        complete = matched is not None
        if complete:
            source_path = str(matched["source"])
        else:
            source_path = assembly_sources.get(name, "")
            if not source_path:
                raise ValueError(f"no assembly source for unmatched function: {name}")
        grouped.setdefault(source_path, []).append({
                "name": name,
                "size": str(size),
                "fuzzy_match_percent": 100.0 if complete else 0.0,
                "address": str(vram),
                "metadata": {"virtual_address": str(vram)},
                "complete": complete,
            })

    units = []
    for source_path, functions in sorted(grouped.items()):
        total = sum(int(function["size"]) for function in functions)
        matched_total = sum(
            int(function["size"]) for function in functions if function.pop("complete")
        )
        matched_count = sum(
            function["fuzzy_match_percent"] == 100.0 for function in functions
        )
        complete = matched_count == len(functions)
        unit_measures = measures(
            total, matched_total, len(functions), matched_count, 1, int(complete)
        )
        units.append({
            "name": source_path,
            "measures": unit_measures,
            "functions": functions,
            "metadata": {
                "complete": complete,
                "source_path": source_path,
                "progress_categories": ["game"],
                "auto_generated": source_path.startswith("asm/"),
            },
        })

    aggregate = measures(
        total_code,
        matched_code,
        len(catalogue),
        matched_functions,
        len(units),
        sum(bool(unit["metadata"]["complete"]) for unit in units),
    )
    return {
        "measures": aggregate,
        "units": units,
        "version": 2,
        "categories": [{"id": "game", "name": "Program code", "measures": aggregate}],
    }


def main() -> None:
    report = build_report()
    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    OUTPUT.write_text(json.dumps(report, indent=2) + "\n")
    matched = report["measures"]["matched_code"]
    total = report["measures"]["total_code"]
    functions = report["measures"]["matched_functions"]
    total_functions = report["measures"]["total_functions"]
    print(f"report: {matched}/{total} code bytes; {functions}/{total_functions} functions")


if __name__ == "__main__":
    main()
