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
| `0x001000-0x0E15EF` | `0xE05F0` | IPL3-loaded program image | CPU code, RSP text, initialized data and rodata |
| `0x0E15F0-0x7FFFFF` | `0x71EA10` | asset/payload region | graphics, referenced ranges, padding and unknown ranges |

These ranges are contiguous, non-overlapping, and cover every byte of the
retail ROM. Boot-path analysis measures the loaded image at
`0x80000400-0x800E09EF`, followed by BSS through `0x80147F0F`.
`superman.yaml` supplies the 152 stable source-unit boundaries, while
`analysis/rom_inventory.tsv` records 1,272 contiguous physical ranges derived
from the Superman ROM itself with `n64-decomp-kit survey` at commit
`45dabb8a7171a065f54f771ef74173118319bd94`.

| Physical class | Bytes |
| --- | ---: |
| Cartridge header and IPL3 | 4,096 |
| CPU and RSP executable code | 875,680 |
| Initialized program data | 43,344 |
| Identified graphics payload | 313,848 |
| Loader-referenced payload | 1,142,904 |
| Padding | 374,888 |
| Unknown | 5,633,848 |

The classes sum to all 8,388,608 ROM bytes. Identification is not matching
credit: only reconstructed source represented by reviewed matching manifests
advances public progress. Run `make inventory` to verify ROM identity,
contiguous coverage, and these class totals.

## Reconstruction gate

The linker places every tracked range back at its original ROM offset,
recomputes the CIC checksums, and verifies the complete output against
`superman.sha1`. The current build reproduces all 8 MiB exactly.
