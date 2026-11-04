#!/usr/bin/env python3
"""Verify reviewed function bodies and non-function text gaps.

The original catalogue used the next symbol as every function's end.  Retail
assembly comments provide the encoded instruction addresses needed to exclude
trailing zero-fill while retaining a control-transfer delay slot.
"""

from __future__ import annotations

import csv
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CATALOGUE = ROOT / "config/us/functions.tsv"
MATCHING = ROOT / "config/us/matching_units.tsv"
GAPS = ROOT / "config/us/nonfunction_ranges.tsv"

INSTRUCTION = re.compile(
    r"/\*\s*([0-9A-Fa-f]+)\s+[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s*\*/"
)


def read_rows(path: Path, fields: tuple[str, ...]) -> list[dict[str, str]]:
    with path.open(newline="") as stream:
        lines = (line for line in stream if line.strip() and not line.startswith("#"))
        return list(csv.DictReader(lines, delimiter="\t", fieldnames=fields))


def has_delay_slot(word: int) -> bool:
    opcode = word >> 26
    if opcode in (1, 2, 3, 4, 5, 6, 7):
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
    instructions: dict[int, int] = {}
    for source in sorted((ROOT / "asm").rglob("*.s")):
        for address, word in INSTRUCTION.findall(source.read_text(errors="replace")):
            instructions[int(address, 16)] = int(word, 16)

    expected_gaps: list[tuple[int, int, int, str]] = []
    for index, row in enumerate(catalogue):
        start = int(row["rom"], 0)
        span_end = (int(catalogue[index + 1]["rom"], 0)
                    if index + 1 < len(catalogue) else 0xD49B0)
        span = span_end - start
        if start in matching:
            expected_size = matching[start]
            evidence = "matching_source"
        else:
            words = [(address, instructions[address]) for address in range(start, start + span, 4)
                     if address in instructions]
            if not words:
                raise ValueError(f"no retail instruction evidence for {row['name']}")
            last_nonzero = max(index for index, (_, word) in enumerate(words) if word != 0)
            last = last_nonzero + (1 if has_delay_slot(words[last_nonzero][1]) else 0)
            last = min(last, len(words) - 1)
            expected_size = words[last][0] + 4 - start
            evidence = "retail_disassembly"
        size = int(row["size"], 0)
        if size != expected_size or row["evidence"] != evidence:
            raise ValueError(f"boundary evidence mismatch for {row['name']}")
        if size <= 0 or size > span or size % 4:
            raise ValueError(f"invalid audited size for {row['name']}")
        if size < span:
            gap_start = start + size
            gap_vram = int(row["vram"], 0) + size
            expected_gaps.append((gap_start, span - size, gap_vram, "alignment"))
    actual_gaps = [
        (int(row["rom"], 0), int(row["size"], 0), int(row["vram"], 0), row["kind"])
        for row in read_rows(GAPS, ("rom", "size", "vram", "kind"))
    ]
    if actual_gaps != expected_gaps:
        raise ValueError("nonfunction ledger differs from audited boundaries")
    print(
        f"audited {len(catalogue)} functions: {sum(int(row['size'], 0) for row in catalogue)} bytes; "
        f"{len(actual_gaps)} gaps: {sum(row[1] for row in actual_gaps)} bytes"
    )


if __name__ == "__main__":
    main()
