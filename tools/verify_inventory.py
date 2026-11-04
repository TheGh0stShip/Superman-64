#!/usr/bin/env python3
import csv
import hashlib
import sys
from pathlib import Path


EXPECTED_SHA1 = "c271db752610c9581e1ba1e9125ea8ecdb56f74f"
ROM_SIZE = 0x800000
REGION_LEDGER = "config/us/rom_regions.tsv"
PHYSICAL_LEDGER = "analysis/rom_inventory.tsv"


def fail(message):
    print(f"inventory: {message}", file=sys.stderr)
    raise SystemExit(1)


def main():
    root = Path(__file__).resolve().parent.parent
    rom_path = root / "baserom.z64"
    ledger_path = root / REGION_LEDGER

    rom = rom_path.read_bytes()
    if len(rom) != ROM_SIZE:
        fail(f"ROM size is 0x{len(rom):X}, expected 0x{ROM_SIZE:X}")
    digest = hashlib.sha1(rom).hexdigest()
    if digest != EXPECTED_SHA1:
        fail(f"ROM SHA-1 is {digest}, expected {EXPECTED_SHA1}")

    cursor = 0
    count = 0
    regions = []
    with ledger_path.open(newline="") as ledger_file:
        for row in csv.DictReader(ledger_file, delimiter="\t"):
            start = int(row["start"], 0)
            end = int(row["end"], 0)
            if start != cursor:
                fail(f"record {count + 1} starts at 0x{start:X}, expected 0x{cursor:X}")
            if end <= start:
                fail(f"record {count + 1} has an invalid range")
            regions.append((start, end, row["kind"]))
            cursor = end
            count += 1

    if cursor != ROM_SIZE:
        fail(f"tail ledger ends at 0x{cursor:X}, expected 0x{ROM_SIZE:X}")
    expected_regions = [
        (0x0, 0x40, "cartridge_header"),
        (0x40, 0x1000, "ipl3_boot"),
        (0x1000, 0xE15F0, "program_image"),
        (0xE15F0, 0x800000, "rom_payload"),
    ]
    if regions != expected_regions:
        fail(f"coarse ROM regions changed: {regions!r}")
    physical_path = root / PHYSICAL_LEDGER
    physical_cursor = 0
    physical_count = 0
    totals = {}
    with physical_path.open(newline="") as physical_file:
        for row in csv.DictReader(physical_file, delimiter="\t"):
            start, end, size = int(row["start"], 0), int(row["end"], 0), int(row["size"], 0)
            if start != physical_cursor or end <= start or end - start != size:
                fail(f"physical record {physical_count + 1} has a gap, overlap, or invalid size")
            totals[row["class"]] = totals.get(row["class"], 0) + size
            physical_cursor = end
            physical_count += 1
    if physical_cursor != ROM_SIZE:
        fail(f"physical ledger ends at 0x{physical_cursor:X}, expected 0x{ROM_SIZE:X}")
    expected = {
        "rom_metadata": 4096,
        "code": 875680,
        "data": 43344,
        "payload": 313848,
        "referenced": 1142904,
        "padding": 374888,
        "unknown": 5633848,
    }
    if totals != expected:
        fail(f"physical class totals changed: {totals!r}")
    print(
        f"inventory: ROM verified; {count} regions and {physical_count} physical records; "
        "full range covered"
    )


if __name__ == "__main__":
    main()
