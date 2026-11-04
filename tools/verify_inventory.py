#!/usr/bin/env python3
import csv
import hashlib
import sys
from pathlib import Path


EXPECTED_SHA1 = "c271db752610c9581e1ba1e9125ea8ecdb56f74f"
ROM_SIZE = 0x800000
TAIL_START = 0x0D49B0


def fail(message):
    print(f"inventory: {message}", file=sys.stderr)
    raise SystemExit(1)


def main():
    root = Path(__file__).resolve().parent.parent
    rom_path = root / "baserom.z64"
    ledger_path = root / "docs" / "rom_inventory_tail.tsv"

    rom = rom_path.read_bytes()
    if len(rom) != ROM_SIZE:
        fail(f"ROM size is 0x{len(rom):X}, expected 0x{ROM_SIZE:X}")
    digest = hashlib.sha1(rom).hexdigest()
    if digest != EXPECTED_SHA1:
        fail(f"ROM SHA-1 is {digest}, expected {EXPECTED_SHA1}")

    cursor = TAIL_START
    count = 0
    with ledger_path.open(newline="") as ledger_file:
        for row in csv.DictReader(ledger_file, delimiter="\t"):
            start = int(row["superman_start"], 16)
            end = int(row["superman_end"], 16)
            size = int(row["size"], 16)
            if start != cursor:
                fail(f"record {count + 1} starts at 0x{start:X}, expected 0x{cursor:X}")
            if end <= start or end - start != size:
                fail(f"record {count + 1} has an invalid range or size")
            cursor = end
            count += 1

    if cursor != ROM_SIZE:
        fail(f"tail ledger ends at 0x{cursor:X}, expected 0x{ROM_SIZE:X}")
    print(f"inventory: ROM verified; {count} contiguous tail records; full range covered")


if __name__ == "__main__":
    main()
