# Superman 64 research survey: 150 rounds

Date: 2026-11-04

This survey records 150 distinct public-source investigations performed for the USA retail byte-matching decompilation. A round is one targeted search question, followed by source triage and a decision about whether the result creates an actionable lead. Repeated index pages, ROM downloads, unverifiable claims, and generic game reviews were rejected. No third-party source is treated as matching C without byte verification.

## Actionable findings

- The surviving 2021 retail and beta branches contain the same decimal-string parser instruction-for-instruction, with only address relocation. This proves the routine predates the retail build and provides a second binary oracle, but not recovered C source.
- Public recompilation material is useful for names, signatures, call relationships, and patch targets. It is supporting evidence only; every name and prototype still requires validation against the retail ROM.
- The September 1998 prototype and other preserved builds are the strongest upstream binary research targets. Cross-version function alignment can expose stable library code, changed game logic, and data-format boundaries.
- ByteMatch consumes objdiff reports and exposes sixteen canonical measures. Accurate tracking therefore requires real code sizes, real data sizes, function membership, and zero-code data units; assembly placeholders must not be counted as matched source.
- BattleTanx demonstrates the expected unresolved-data model: data ranges may be separate zero-code units, while code units contain functions and actual compilation-unit extents.
- Searches of broad social networks, generic game databases, and unrelated decimal parsers produced no source recovery and are closed unless a new concrete lead appears.

## Priority queue produced by the survey

1. Preserve and compare every legally available prototype/regional executable as a binary oracle; align functions by normalized instruction fingerprints.
2. Extract public symbol/configuration material from the recompilation project and verify each item against retail callsites.
3. Mine the beta branch for identical and near-identical functions, separating stable runtime/library code from game-specific changes.
4. Compare build flags, report configuration, and unit/data modeling with Rugrats, Nagano, BattleTanx, and BattleTanx: Global Assault.
5. Search Titus sibling titles for shared engine/runtime routines by instruction fingerprints, never by names alone.
6. Continue IDO source-shape experiments for near-matches, using the prototype build as a second equality check.

## Round ledger

| Round | Investigation |
|---:|---|
| 1 | "Superman 64" source code decompilation prototype debug symbols Titus |
| 2 | "Superman: The New Superman Adventures" ROM map symbols source |
| 3 | site:github.com Superman64 decomp OR "Superman 64" N64 source |
| 4 | site:gitlab.com OR site:codeberg.org "Superman 64" decomp |
| 5 | "Superman64Decomp" |
| 6 | "Superman64Decomp" symbols |
| 7 | "Superman64Decomp" functions |
| 8 | "Superman64Decomp" linker |
| 9 | github "farisawan-2000/superman" |
| 10 | github "gcsmith/Superman64Decomp" |
| 11 | github "Superman64Recomp" symbols |
| 12 | github "Superman64Recomp" patches |
| 13 | "func_800040A0" |
| 14 | "800040A0" Superman |
| 15 | "main_4CA0" N64 |
| 16 | "parse decimal" N64 decomp |
| 17 | site:github.com "func_800CD49C" |
| 18 | site:github.com "800CD49C" |
| 19 | site:github.com "D_800" "Superman64" |
| 20 | site:github.com "superman.us.toml" |
| 21 | Superman 64 September 1998 prototype differences code |
| 22 | Superman 64 prototype ROM versions Hidden Palace |
| 23 | Superman 64 beta debug menu symbols |
| 24 | Superman 64 regional ROM USA Europe France differences |
| 25 | Titus Interactive Nintendo 64 source code archive |
| 26 | Titus Software N64 engine source code |
| 27 | Titus Superman 64 developer interview Eric Caen |
| 28 | Titus Superman 64 programmer credits |
| 29 | Superman 64 credits programmer names |
| 30 | Superman 64 development tools SGI IDO |
| 31 | Superman 64 compiler IDO version |
| 32 | Superman 64 ROM header compiler fingerprint |
| 33 | Superman 64 debug strings ROM |
| 34 | Superman 64 unused content The Cutting Room Floor |
| 35 | Superman 64 prototype Unseen64 |
| 36 | Superman 64 source Video Game History Foundation |
| 37 | Titus Interactive archive source code preservation |
| 38 | Superman 64 assets models archive |
| 39 | Superman 64 reverse engineering forum |
| 40 | Superman 64 romhacking.net |
| 41 | Rugrats N64 decomp GitHub progress report |
| 42 | Rugrats Search for Reptar decomp decomp.dev |
| 43 | Rugrats N64 decomp matching functions data progress |
| 44 | Rugrats N64 decomp splat config |
| 45 | Nitro64 Nagano Winter Olympics decomp GitHub |
| 46 | Nagano Winter Olympics 98 N64 decomp progress |
| 47 | Nagano N64 decomp decomp.dev |
| 48 | Nagano Winter Olympics source symbols |
| 49 | BattleTanx N64 decomp GitHub |
| 50 | BattleTanx decomp progress report data |
| 51 | BattleTanx N64 decomp decomp.dev |
| 52 | BattleTanx symbols map source |
| 53 | BattleTanx Global Assault N64 decomp GitHub |
| 54 | BattleTanx Global Assault decomp progress |
| 55 | BattleTanx Global Assault decomp.dev |
| 56 | 3DO BattleTanx engine source code |
| 57 | bytematch Rugrats N64 |
| 58 | bytematch Nagano N64 |
| 59 | bytematch BattleTanx N64 |
| 60 | decomp.dev progress report artifact VERSION_report |
| 61 | site:github.com/n64decomp "multiplier *= 10" |
| 62 | site:github.com/decompals "multiplier *= 10" |
| 63 | site:github.com "index >= 0" "multiplier" N64 |
| 64 | site:github.com "text[index]" "multiplier *= 10" |
| 65 | site:github.com N64 decomp atoi implementation IDO |
| 66 | site:github.com N64 decomp strtol decimal backwards |
| 67 | site:github.com libultra atoi source |
| 68 | site:github.com nusys atoi N64 |
| 69 | IDO compiler epilogue instruction scheduling lw ra return value |
| 70 | IDO 5.3 C compiler scheduler source line matching decomp |
| 71 | decomp permuter final epilogue load ordering IDO |
| 72 | mips IDO lw v0 lw ra epilogue scheduling |
| 73 | site:decomp.me MIPS decimal string parser |
| 74 | site:decomp.me "multiplier" MIPS |
| 75 | site:decomp.me "func_800040A0" |
| 76 | site:decomp.me Superman 64 |
| 77 | libreultra source strlen implementation |
| 78 | Superman 64 libultra version identify |
| 79 | Superman 64 SDK functions symbols |
| 80 | Superman 64 OS library functions addresses |
| 81 | site:archive.org Superman 64 prototype |
| 82 | site:archive.org Titus Interactive Superman development |
| 83 | site:hiddenpalace.org Superman 64 prototype |
| 84 | site:tcrf.net Superman 64 |
| 85 | site:assemblergames.org Superman 64 beta |
| 86 | site:obscuregamers.com Superman 64 prototype |
| 87 | site:reddit.com Superman64Decomp |
| 88 | site:reddit.com "Superman 64" prototype source |
| 89 | site:youtube.com Superman 64 developer interview |
| 90 | site:x.com Superman64Decomp |
| 91 | site:twitter.com Superman64Decomp |
| 92 | site:discord.com Superman 64 decomp |
| 93 | site:gitlab.com "Superman64" |
| 94 | site:codeberg.org "Superman64" |
| 95 | site:sourceforge.net Superman 64 reverse engineering |
| 96 | site:gitea.com Superman64Decomp |
| 97 | "farisawan-2000/superman" fork |
| 98 | "gcsmith/Superman64Decomp" fork |
| 99 | "Superman64Decomp" mirror |
| 100 | "Superman64Decomp" archive |
| 101 | gcsmith Superman64Recomp superman.us.toml raw |
| 102 | gcsmith Superman64Recomp include symbols |
| 103 | gcsmith Superman64Recomp patches functions |
| 104 | gcsmith Superman64Recomp function names |
| 105 | site:github.com/gcsmith/Superman64Recomp "800040A0" |
| 106 | site:github.com/gcsmith/Superman64Recomp "800CD49C" |
| 107 | site:github.com/gcsmith/Superman64Recomp "Superman64Decomp" |
| 108 | site:github.com/gcsmith/Superman64Recomp "func_" |
| 109 | Superman 64 USA ROM CRC serial |
| 110 | Superman 64 Europe ROM CRC |
| 111 | Superman 64 prototype ROM CRC |
| 112 | Superman 64 ROM database hashes |
| 113 | Superman 64 memory map N64 |
| 114 | Superman 64 Gameshark code addresses |
| 115 | Superman 64 hacking documentation |
| 116 | Superman 64 texture format model format |
| 117 | Titus Roadsters N64 decompilation |
| 118 | Titus Blues Brothers 2000 N64 decompilation |
| 119 | Titus Virtual Chess 64 decompilation |
| 120 | Titus Automobili Lamborghini N64 decompilation |
| 121 | site:github.com Rugrats N64 decomp "report.json" |
| 122 | site:github.com Nagano N64 decomp "report.json" |
| 123 | site:github.com battletanx-decomp "report.json" |
| 124 | site:github.com BattleTanx-Global-Assault "report.json" |
| 125 | site:github.com Rugrats N64 decomp "data" "progress" |
| 126 | site:github.com Nagano N64 decomp "data" "progress" |
| 127 | site:github.com battletanx-decomp "data" "progress" |
| 128 | site:github.com BattleTanx-Global-Assault "data" "progress" |
| 129 | decomp.dev report schema categories data code functions |
| 130 | bytematch report artifact schema unit map |
| 131 | bytematch VERSION_report artifact GitHub Actions |
| 132 | decomp.dev history import report artifact |
| 133 | objdiff report.json N64 decomp progress |
| 134 | splat progress report data matching N64 |
| 135 | decomp-toolkit progress categories data |
| 136 | mapfile_parser progress report N64 |
| 137 | IDO matching decomp source patterns repository |
| 138 | decompals ido matching decomp examples |
| 139 | mips_to_c IDO matching tips epilogue |
| 140 | decomp permuter IDO randomization techniques |
| 141 | N64 decomp function boundary detection tools |
| 142 | N64 ROM data asset inventory splat |
| 143 | N64 decomp rodata matching progress |
| 144 | N64 decomp linker map data categories |
| 145 | Superman 64 MIPS function signatures |
| 146 | Superman 64 strings extraction |
| 147 | Superman 64 audio bank format |
| 148 | Superman 64 level archive format |
| 149 | Superman 64 prototype retail binary diff |
| 150 | Superman 64 European USA binary diff |

## Principal public sources retained

- [ByteMatch setup and report ingestion](https://bytematch.dev/docs/getting-started)
- [ByteMatch report measures and API](https://bytematch.dev/docs/api)
- [BattleTanx tracker example](https://bytematch.dev/AbuN64/battletanx-decomp)
- [BattleTanx repository](https://github.com/AbuN64/battletanx-decomp)
- [BattleTanx: Global Assault repository](https://github.com/TheGh0stShip/BattleTanx-Global-Assault)
- [September 1998 prototype description](https://hiddenpalace.org/w/index.php?title=Superman_64_%28Sep_6%2C_1998_prototype%29)
- [Prototype technical comparison](https://micro-64.com/features/supermanbeta.shtml)
- [IDO matching examples](https://github.com/decompals/ido-matching-decomp)
- [decomp-permuter](https://github.com/simonlindholm/decomp-permuter)
- [objdiff](https://github.com/encounter/objdiff)
- [N64 development references](https://github.com/command-tab/awesome-n64-development)

## Evidence rules

Public search results can suggest names, data formats, compiler patterns, or binary versions. They do not establish authorship or matching status. A reconstructed function is credited only after its object bytes match the retail ROM and the full ROM build passes. Handwritten assembly retains provenance rather than being presented as reconstructed C.
