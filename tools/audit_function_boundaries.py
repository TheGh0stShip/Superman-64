#!/usr/bin/env python3
"""Verify reviewed function bodies and non-function text gaps.

The original catalogue used the next symbol as every function's end.  Retail
assembly comments provide the encoded instruction addresses needed to exclude
trailing zero-fill while retaining a control-transfer delay slot.
"""

from __future__ import annotations

import csv
import re
import tomllib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CATALOGUE = ROOT / "config/us/functions.tsv"
MATCHING = ROOT / "config/us/matching_units.tsv"
GAPS = ROOT / "config/us/nonfunction_ranges.tsv"
SURVEY = ROOT / "analysis/survey/functions.toml"
CODE_END = 0xD4A04
EMBEDDED_DATA = {(0xBF7C8, 0x14), (0xBFAD0, 0x10), (0xD49B0, 0x30)}
PROGRAM_DATA = {(0x1040, 0x20)}

INSTRUCTION = re.compile(
    r"/\*\s*([0-9A-Fa-f]+)\s+[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s*\*/"
)


def read_rows(path: Path, fields: tuple[str, ...]) -> list[dict[str, str]]:
    with path.open(newline="") as stream:
        lines = (line for line in stream if line.strip() and not line.startswith("#"))
        return list(csv.DictReader(lines, delimiter="\t", fieldnames=fields))


def has_delay_slot(word: int) -> bool:
    opcode = word >> 26
    if opcode in (1, 2, 3, 4, 5, 6, 7, 20, 21, 22, 23):
        return True
    if opcode == 0 and (word & 0x3F) in (8, 9):
        return True
    return opcode in (16, 17, 18, 19) and ((word >> 21) & 0x1F) == 8


def main() -> None:
    catalogue = read_rows(CATALOGUE, ("rom", "size", "vram", "name", "evidence"))
    matching = {
        int(row["rom"], 0): int(row["size"], 0)
        for row in read_rows(
            MATCHING, ("rom", "size", "vram", "name", "source", "sha256")
        )
    }
    section = tomllib.loads(SURVEY.read_text())["section"][0]
    rom_delta = int(section["vram"]) - int(section["rom"])
    surveyed = {
        int(row["vram"]) - rom_delta: int(row["size"])
        for row in section["functions"]
    }
    starts = [int(row["rom"], 0) for row in catalogue]
    if starts != sorted(set(starts)):
        raise ValueError("function catalogue is not strictly ordered and unique")
    if set(starts) != set(surveyed):
        missing = sorted(set(surveyed) - set(starts))
        extra = sorted(set(starts) - set(surveyed))
        raise ValueError(f"function catalogue differs from retail survey: {missing=}, {extra=}")
    instructions: dict[int, int] = {}
    for source in sorted((ROOT / "asm").rglob("*.s")):
        for address, word in INSTRUCTION.findall(source.read_text(errors="replace")):
            instructions[int(address, 16)] = int(word, 16)

    expected_gaps: list[tuple[int, int, int, str]] = []
    for index, row in enumerate(catalogue):
        start = int(row["rom"], 0)
        span_end = (int(catalogue[index + 1]["rom"], 0)
                    if index + 1 < len(catalogue) else CODE_END)
        span = span_end - start
        if start in matching:
            expected_size = matching[start]
            evidence = "matching_source"
        else:
            words = [(address, instructions[address]) for address in range(start, start + span, 4)
                     if address in instructions]
            if words:
                last_nonzero = max(index for index, (_, word) in enumerate(words) if word != 0)
                last = last_nonzero + (1 if has_delay_slot(words[last_nonzero][1]) else 0)
                last = min(last, len(words) - 1)
                expected_size = words[last][0] + 4 - start
                expected_size = min(expected_size, surveyed.get(start, expected_size))
                evidence = "retail_disassembly"
            else:
                expected_size = surveyed.get(start, 0)
                evidence = "survey_disassembly"
        size = int(row["size"], 0)
        if size != expected_size or row["evidence"] != evidence:
            raise ValueError(f"boundary evidence mismatch for {row['name']}")
        if size <= 0 or size > span or size % 4:
            raise ValueError(f"invalid audited size for {row['name']}")
        if size < span:
            gap_start = start + size
            gap_vram = int(row["vram"], 0) + size
            gap_end = start + span
            cursor = gap_start
            classified = [(start, size, "embedded_data") for start, size in EMBEDDED_DATA]
            classified += [(start, size, "program_data") for start, size in PROGRAM_DATA]
            for data_start, data_size, data_kind in sorted(classified):
                data_end = data_start + data_size
                if data_start < gap_start or data_end > gap_end:
                    continue
                if cursor < data_start:
                    expected_gaps.append((cursor, data_start - cursor,
                                          gap_vram + cursor - gap_start, "alignment"))
                expected_gaps.append((data_start, data_size,
                                      gap_vram + data_start - gap_start, data_kind))
                cursor = data_end
            if cursor < gap_end:
                expected_gaps.append((cursor, gap_end - cursor,
                                      gap_vram + cursor - gap_start, "alignment"))
    actual_gaps = [
        (int(row["rom"], 0), int(row["size"], 0), int(row["vram"], 0), row["kind"])
        for row in read_rows(GAPS, ("rom", "size", "vram", "kind"))
    ]
    if actual_gaps != expected_gaps:
        mismatch = next(
            ((actual, expected) for actual, expected in zip(actual_gaps, expected_gaps)
             if actual != expected),
            (actual_gaps[len(expected_gaps):], expected_gaps[len(actual_gaps):]),
        )
        raise ValueError(f"nonfunction ledger differs from audited boundaries: {mismatch}")
    print(
        f"audited {len(catalogue)} functions: {sum(int(row['size'], 0) for row in catalogue)} bytes; "
        f"{len(actual_gaps)} gaps: {sum(row[1] for row in actual_gaps)} bytes"
    )


if __name__ == "__main__":
    main()
