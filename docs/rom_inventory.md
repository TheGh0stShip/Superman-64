# ROM inventory

## Identity

| Property | Value |
| --- | --- |
| Size | `0x800000` (8,388,608 bytes) |
| Byte order | big-endian (`.z64`) |
| SHA-1 | `c271db752610c9581e1ba1e9125ea8ecdb56f74f` |
| MD5 | `3f64b4f72e61225ef3ae93976c9bfc7c` |
| Internal title | `SUPERMAN` |
| Game code | `NSPE` |
| Entry point | `0x80000400` |
| CIC | `CIC-NUS-6102` |
| Header CRC1 | `0xA2E8F35B` |
| Header CRC2 | `0xC9DC87D9` |

## Complete address coverage

| ROM range | Size | Classification | Tracked representation |
| --- | ---: | --- | --- |
| `0x000000-0x00003F` | `0x40` | cartridge header | `asm/header.s` |
| `0x000040-0x000FFF` | `0xFC0` | IPL3 boot code | extracted `bin/boot.bin` |
| `0x001000-0x0D49AF` | `0xD39B0` | resident MIPS code | 153 ordered units in `superman.yaml`; C and assembly sources |
| `0x0D49B0-0x7FFFFF` | `0x72B650` | shared Titus engine payload | 2,102 contiguous records in `docs/rom_inventory_tail.tsv` |

These ranges are contiguous, non-overlapping, and cover every byte of the
retail ROM. `superman.yaml` is the authoritative ordered inventory of all 153
known resident code-unit boundaries. The tail ledger classifies every byte as
code, initialized program data, audio, display-list data, archive indexes,
archive records, or alignment fill. It contains 403 code records, 477 program
data records, 348 audio records, one display-list record, two archive indexes,
493 archive records, and 378 fill records.

The entire tail is byte-identical to the range `0x0373F0-0x762A3F` in the
North American Rugrats 64 ROM. Its physical record boundaries were translated
by adding `0x09D5C0`; the original offsets are retained in the last two ledger
columns. This is an exact shared-payload mapping, not a similarity inference.
Run `make inventory` to verify the ROM identity and contiguous ledger coverage.

## Reconstruction gate

The linker places every tracked range back at its original ROM offset,
recomputes the CIC checksums, and verifies the complete output against
`superman.sha1`. The current build reproduces all 8 MiB exactly.
