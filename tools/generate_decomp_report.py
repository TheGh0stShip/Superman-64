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
ROM_REGIONS = ROOT / "config/us/rom_regions.tsv"
SPLAT_CONFIG = ROOT / "superman.yaml"
ROM_INVENTORY = ROOT / "analysis/rom_inventory.tsv"
OUTPUT = ROOT / "build/report.json"

CODE_ROM_START = 0x1000
CODE_ROM_END = 0xD4A04
CODE_VRAM_START = 0x80000400
ROM_SIZE = 0x800000
PROGRAM_TEXT_END = 0xD6CC0


def measures(total_code: int, matched_code: int, total_functions: int,
             matched_functions: int, total_units: int,
             complete_units: int, complete_code: int | None = None) -> dict[str, object]:
    if complete_code is None:
        complete_code = matched_code
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
        "complete_code": str(complete_code),
        "complete_code_percent": (
            complete_code * 100.0 / total_code if total_code else 0.0
        ),
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


def read_code_units() -> list[tuple[int, int, str]]:
    """Read the authoritative resident-code unit boundaries from Splat."""
    starts: list[int] = []
    in_subsections = False
    entry = re.compile(
        r"^\s+- \[(0x[0-9A-Fa-f]+)\s*,\s*(asm|hasm|c)(?:\s*,[^\]]+)?\]\s*(?:#.*)?$"
    )
    for line in SPLAT_CONFIG.read_text().splitlines():
        if line.strip() == "subsections:":
            in_subsections = True
            continue
        if not in_subsections:
            continue
        match = entry.match(line)
        if match:
            starts.append(int(match.group(1), 0))
        elif line.startswith("  - "):
            break
    if (not starts or starts != sorted(set(starts))
            or starts[0] != CODE_ROM_START or starts[-1] >= CODE_ROM_END):
        raise ValueError("invalid or duplicate Splat code-unit boundaries")
    ends = starts[1:] + [CODE_ROM_END]
    return [
        (start, end, f"src/main_{start:X}.c")
        for start, end in zip(starts, ends)
    ]


def read_rom_regions() -> list[dict[str, int | str]]:
    rows: list[dict[str, int | str]] = []
    with ROM_REGIONS.open(newline="") as stream:
        reader = csv.DictReader(stream, delimiter="\t")
        cursor = 0
        for row in reader:
            start, end = int(row["start"], 0), int(row["end"], 0)
            if start != cursor or end <= start:
                raise ValueError("ROM region ledger has a gap, overlap, or empty range")
            rows.append({"start": start, "end": end, "kind": row["kind"]})
            cursor = end
    if cursor != ROM_SIZE:
        raise ValueError("ROM region ledger does not cover the complete ROM")
    return rows


def read_rom_inventory() -> list[dict[str, int | str]]:
    rows: list[dict[str, int | str]] = []
    with ROM_INVENTORY.open(newline="") as stream:
        cursor = 0
        for row in csv.DictReader(stream, delimiter="\t"):
            start, end, size = int(row["start"], 0), int(row["end"], 0), int(row["size"], 0)
            if start != cursor or end <= start or end - start != size:
                raise ValueError("physical ROM inventory has a gap, overlap, or invalid size")
            rows.append({**row, "start_int": start, "end_int": end, "size_int": size})
            cursor = end
    if cursor != ROM_SIZE:
        raise ValueError("physical ROM inventory does not cover the complete ROM")
    return rows


def inventory_bytes(rows: list[dict[str, int | str]], *, class_name: str,
                    category: str | None = None) -> int:
    return sum(
        int(row["size_int"]) for row in rows
        if row["class"] == class_name and (category is None or row["category"] == category)
    )


def code_bytes_in_range(rows: list[dict[str, int | str]], start: int, end: int) -> int:
    return sum(
        max(0, min(end, int(row["end_int"])) - max(start, int(row["start_int"])))
        for row in rows if row["class"] == "code"
    )


def validate_nonfunction_classes(nonfunction: list[dict[str, int | str]],
                                 inventory: list[dict[str, int | str]]) -> None:
    for item in nonfunction:
        start = int(item["start"])
        end = start + int(item["size"])
        expected = "data" if item["kind"] == "program_data" else "code"
        overlaps = [
            row for row in inventory
            if int(row["start_int"]) < end and start < int(row["end_int"])
        ]
        if not overlaps or any(row["class"] != expected for row in overlaps):
            raise ValueError(
                f"nonfunction {item['kind']} at {start:#x} disagrees with physical inventory"
            )


def data_category_measures(total: int, matched: int = 0) -> dict[str, object]:
    # Data-only categories must not also claim their bytes as code. Trackers
    # aggregate and visualize these fields independently.
    result = measures(0, 0, 0, 0, 0, 0)
    percent = matched * 100.0 / total if total else 0.0
    result.update({
        "total_data": str(total),
        "matched_data": str(matched),
        "matched_data_percent": percent,
        "complete_data": str(matched),
        "complete_data_percent": percent,
    })
    return result


def build_report() -> dict[str, object]:
    catalogue = read_catalogue()
    nonfunction = read_nonfunction_ranges()
    validate_image_coverage(catalogue, nonfunction)
    rows = read_manifest(catalogue)
    matched_by_start = {int(row["start"]): row for row in rows}
    read_rom_regions()
    inventory = read_rom_inventory()
    validate_nonfunction_classes(nonfunction, inventory)
    code_units = read_code_units()
    total_code = inventory_bytes(inventory, class_name="code", category="program")
    matched_code = sum(int(row["size_int"]) for row in rows)
    matched_functions = len(rows)
    grouped: dict[str, list[dict[str, object]]] = {
        source_path: [] for _, _, source_path in code_units
    }
    for function in catalogue:
        start = int(function["start"])
        size = int(function["size_int"])
        vram = int(function["vram_int"])
        name = str(function["name"])
        matched = matched_by_start.get(start)
        complete = matched is not None
        owners = [unit for unit in code_units if unit[0] <= start < unit[1]]
        if len(owners) != 1:
            raise ValueError(f"function does not have exactly one code unit: {name}")
        source_path = owners[0][2]
        generated = not complete
        grouped.setdefault(source_path, []).append({
                "name": name,
                "size": str(size),
                "fuzzy_match_percent": 100.0 if complete else 0.0,
                "address": str(vram),
                "metadata": {"virtual_address": str(vram)},
                "complete": complete,
                "generated": generated,
            })

    units = []
    for unit_start, unit_end, source_path in code_units:
        functions = grouped[source_path]
        if not functions:
            raise ValueError(f"code unit has no catalogued function: {source_path}")
        total = code_bytes_in_range(inventory, unit_start, unit_end)
        matched_body = sum(
            int(function["size"]) for function in functions if function.pop("complete")
        )
        auto_generated = any([function.pop("generated") for function in functions])
        matched_count = sum(
            function["fuzzy_match_percent"] == 100.0 for function in functions
        )
        complete = matched_count == len(functions)
        matched_total = total if complete else matched_body
        unit_measures = measures(
            total, matched_total, len(functions), matched_count, 1, int(complete),
            total if complete else 0,
        )
        units.append({
            "name": source_path,
            "measures": unit_measures,
            "functions": functions,
            "metadata": {
                "complete": complete,
                "source_path": source_path,
                "progress_categories": ["cpu_units"],
                "auto_generated": auto_generated,
            },
        })

    total_data = inventory_bytes(inventory, class_name="data", category="program")
    manifest_matched_code = sum(int(row["size_int"]) for row in rows)
    unit_matched_code = sum(int(unit["measures"]["matched_code"]) for unit in units)
    unit_complete_code = sum(int(unit["measures"]["complete_code"]) for unit in units)
    unit_total_code = sum(int(unit["measures"]["total_code"]) for unit in units)
    matched_function_code = sum(
        int(function["size"])
        for unit in units for function in unit["functions"]
        if function["fuzzy_match_percent"] == 100.0
    )
    if manifest_matched_code != matched_function_code:
        raise ValueError("matching manifest differs from matched function bodies")
    if unit_total_code > total_code:
        raise ValueError("source-unit code exceeds the executable inventory")
    rsp_code = sum(
        int(row["size_int"]) for row in inventory
        if (row["class"] == "code" and row["category"] == "program"
            and row["kind"] == "rsp_text")
    )
    cpu_tail_code = total_code - unit_total_code - rsp_code
    if cpu_tail_code < 0:
        raise ValueError("CPU/RSP category accounting exceeds executable code")
    physical_tail_code = code_bytes_in_range(
        inventory, CODE_ROM_END, PROGRAM_TEXT_END
    )
    if physical_tail_code != cpu_tail_code + rsp_code:
        raise ValueError("CPU-tail and RSP categories disagree with physical inventory")
    if unit_matched_code < manifest_matched_code:
        raise ValueError("source-unit matched code is below matching function bytes")
    matched_code = unit_matched_code

    aggregate = measures(
        total_code,
        matched_code,
        len(catalogue),
        matched_functions,
        len(code_units),
        sum(bool(unit["metadata"]["complete"]) for unit in units),
        unit_complete_code,
    )
    aggregate.update({
        "total_data": str(total_data),
        "matched_data": "0",
        "matched_data_percent": 0.0,
        "complete_data": "0",
        "complete_data_percent": 0.0,
    })
    unit_code_measures = measures(
        unit_total_code, unit_matched_code, len(catalogue), matched_functions,
        len(code_units),
        sum(bool(unit["metadata"]["complete"]) for unit in units),
        unit_complete_code,
    )
    categories = [
        {"id": "cpu_units", "name": "Resident CPU source units", "measures": unit_code_measures},
        {"id": "cpu_tail", "name": "Uncatalogued CPU text", "measures": measures(cpu_tail_code, 0, 0, 0, 0, 0)},
        {"id": "rsp", "name": "RSP text", "measures": measures(rsp_code, 0, 0, 0, 0, 0)},
        {"id": "data", "name": "Initialized program data", "measures": data_category_measures(total_data)},
        {"id": "graphics", "name": "Identified graphics payload", "measures": data_category_measures(inventory_bytes(inventory, class_name="payload", category="graphics"))},
        {"id": "referenced", "name": "Loader-referenced payload", "measures": data_category_measures(inventory_bytes(inventory, class_name="referenced"))},
        {"id": "unknown", "name": "Unclassified ROM payload", "measures": data_category_measures(inventory_bytes(inventory, class_name="unknown"))},
        {"id": "padding", "name": "ROM padding", "measures": data_category_measures(inventory_bytes(inventory, class_name="padding"))},
        {"id": "metadata", "name": "Cartridge header and IPL3", "measures": data_category_measures(inventory_bytes(inventory, class_name="rom_metadata"))},
    ]
    return {
        "measures": aggregate,
        "units": units,
        "version": 2,
        "categories": categories,
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
