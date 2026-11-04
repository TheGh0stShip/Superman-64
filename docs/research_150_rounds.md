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

## Branching N64 ecosystem expansion: 157 rounds

A second campaign expanded the survey by 157 numbered investigations. It did
not stop at project landing pages: each useful result was followed through
source paths, version branches, forks, mirrors, symbol lists, build flags,
object ordering, commit history, and independent comparison projects before
being retained. No candidate from this campaign was credited as matching code.

The broadest catalogues located during this pass enumerate 97 N64
decompilation entries on [decomps.net](https://decomps.net/?f=1&platform=n64&type=decompilation),
74 on the [Recomp project catalogue](https://recompsoftware.com/decompiled-games-list/),
and the independently maintained [N64 development directory](https://n64.dev/).
Their combined project and mirror set was checked across GitHub organizations,
GitLab originals and mirrors, Codeberg, repository search indexes, archival
snapshots, preservation databases, historical forums, and public prototype
records. Duplicate ports, abandoned mirrors, and static translations were
kept distinct from matching source projects.

The resulting comparison corpus covers AeroGauge, Aidyn Chronicles, Animal
Forest, Banjo-Kazooie, Banjo-Tooie, BattleTanx, BattleTanx: Global Assault,
Beetle Adventure Racing, Blast Corps, Body Harvest, the Bomberman series,
Castlevania 64, both Chameleon Twist games, Conker's Bad Fur Day, Dark Rift,
Diddy Kong Racing, Dinosaur Planet, Donkey Kong 64, Doom 64, Doraemon,
Dr. Mario 64, both N64 Duke Nukem projects, F-Zero X and its expansion,
Gauntlet Legends, Gex 64, Glover, GoldenEye 007, Harvest Moon 64, Hybrid
Heaven, Jet Force Gemini, Kirby 64, Lego Racers, Mario Golf, Mario Kart 64,
all three Mario Party games, Mario Tennis, Mischief Makers, Mystical Ninja,
Neon Genesis Evangelion, Onegai Monsters, Paper Mario, Perfect Dark,
Pilotwings 64, Pokemon Puzzle League, Pokemon Snap, both Pokemon Stadium
games, Quest 64, Rocket, Shadowgate 64, both Snowboard Kids games, Space
Station Silicon Valley, Star Fox 64, Shadows of the Empire, Super Mario 64,
Super Smash Bros., The New Tetris, the Turok projects, Virtual Pool 64,
Virtual Pro Wrestling 2, Wave Race 64, Wonder Project J2, Yoshi's Story, and
the other public entries indexed by those catalogues. Titus sibling-title
searches additionally covered Roadsters, Blues Brothers 2000, Virtual Chess
64, and Automobili Lamborghini; no matching source project for those titles
was established.

### Groomed technical findings

- Superman's controller-pak objects consistently identify the pre-J 2.0I
  source family. Independent projects using later library revisions produce
  different object sizes, providing useful negative evidence rather than only
  coincidental symbol matches.
- `pfschecker.c` compiled for VERSION_I with IDO `-O1` produces the exact
  three-body layout `0x6C4, 0x1B4, 0x1E8`, totaling `0xA60`. The remaining
  retail range `0xD1610-0xD206F` has the same three boundaries. The complete
  object is now integrated and ROM-exact.
- `pfsinitpak.c` under the same configuration produces a `0x294` public body
  in a `0x2A0` text object. The retail body at `0xD1130` is also `0x294`, with
  twelve following non-function bytes. The complete object is now integrated
  and ROM-exact.
- Other compiled VERSION_I PFS layouts now provide mechanical search keys:
  `contpfs` is `0xD60`; `pfsreadwritefile` is `0x520`;
  `pfsallocatefile` is `0x7B0`; `pfsfreeblocks` is `0x150`;
  `pfssearchfile` is `0x1C0`; and `pfsdeletefile` is `0x620`.
- Relocation-masked object fingerprints are the best scalable next step.
  Jump targets and linker-resolved high/low immediates should be masked while
  PC-relative branches remain significant. This is stronger than size-only
  matching and can be run locally across the catalogued source corpus.
- The September 1998 prototype remains a valuable second binary oracle for
  identifying stable engine objects, but it cannot establish retail source
  provenance by itself.
- Public static-translation configurations can corroborate addresses,
  signatures, and behavior. They are not accepted as original source or as
  proof of matching names.

### Expanded primary references

- [decompals ultralib](https://github.com/decompals/ultralib)
- [N64 OS version and patch research](https://github.com/akopetsch/n64os-info)
- [n64sym library coverage](https://github.com/shygoo/n64sym/blob/master/included-libs.md)
- [n64decomp organization](https://github.com/n64decomp)
- [Hybrid Heaven object fingerprinting precedent](https://github.com/ogdanimal/HybridHeaven-Decomp)
- [Superman retail configuration cross-check](https://github.com/gcsmith/Superman64Recomp)
- [September 1998 prototype record](https://hiddenpalace.org/w/index.php?title=Superman_64_%28Sep_6%2C_1998_prototype%29)
- [Titus archive holdings](https://gameinformer.com/2019/05/31/as-superman-64-turns-20-we-dig-up-some-relics-from-the-past)

## Ecosystem-wide N64 source-reconstruction census

The follow-up census deliberately went beyond completed projects. It
cross-reconciled the current 74-entry N64 decompilation registry, the broader
90-entry community catalogue, historical lists, direct forge checks, moved
repositories, mirrors, and deleted-but-referenced projects. A reachable
repository is not assumed active, and an unknown region or revision remains
unknown rather than being inferred.

Primary registry evidence:

- [Recomp N64 catalogue](https://recompsoftware.com/platforms/nintendo-64/)
- [decomps.net N64 filter](https://decomps.net/?platform=n64&type=decompilation)
- [decmp.dev tracker](https://www.decmp.dev/)
- [community decompilation catalogue](https://github.com/AlperOZCAN/RetroGames-AllGameDecompilations-2)
- [curated N64 development list](https://github.com/command-tab/awesome-n64-development#game-decompilation)
- [February 2022 historical snapshot](https://www.reddit.com/r/n64/comments/ssas1b/every_n64_decompilation_project_2_microcode/)

### Verified source-reconstruction repositories

- AeroGauge: <https://github.com/LLONSIT/AeroGauge>
- Aidyn Chronicles: <https://github.com/blackgamma7/Aidyn>
- Animal Forest: <https://github.com/zeldaret/af>
- Banjo-Kazooie: <https://gitlab.com/banjo.decomp/banjo-kazooie>
- Banjo-Tooie: <https://github.com/mr-wiseguy/banjo-tooie>
- Beetle Adventure Racing: <https://github.com/synamaxmusic/bar-decomp>
- Blast Corps: <https://github.com/retroplastic/blastcorps>
- Body Harvest: <https://github.com/jaytheham/body-harvest-decompilation>
- Bomberman 64: <https://github.com/bomberhackers/bm64>
- Bomberman 64: The Second Attack: <https://github.com/bomberhackers/tsa>
- Bomberman Hero: <https://github.com/bomberhackers/bmhero>
- Castlevania 64: <https://github.com/blazkowolf/cv64>
- Chameleon Twist, Japanese 1.0: <https://github.com/chameleontwistret/chameleontwistv1.0-jp>
- Chameleon Twist 2, Japanese 1.0: <https://github.com/chameleontwistret/chameleontwist2v1.0-jp>
- Conker's Bad Fur Day: <https://github.com/mkst/conker>
- Conker alternate lineage: <https://github.com/DevOldSchool/conkers-bfd-decomp>
- Dark Rift: <https://github.com/unnunu/darkrift>
- Diddy Kong Racing: <https://github.com/davidsm64/diddy-kong-racing>
- Dinosaur Planet: <https://github.com/zestydevy/dinosaur-planet>
- Donkey Kong 64: <https://gitlab.com/dk64_decomp/dk64>
- Doraemon: <https://github.com/prakxo/doraemon1>
- Dr. Mario 64: <https://github.com/angheloalf/drmario64>
- Duke Nukem: Zero Hour: <https://github.com/gillou68310/dukenukemzerohour>
- Evo's Space Adventures: <https://github.com/mkst/esa>
- F-Zero X: <https://github.com/inspectredc/fzerox>
- F-Zero X Expansion Kit: <https://github.com/inspectredc/fzerox-expansion-kit>
- Gauntlet Legends: <https://github.com/drahsid/gauntlet-legends>
- Gex 64: <https://github.com/matbourgon/gex64decomp>
- Glover: <https://github.com/rainchus/glover>
- GoldenEye 007: <https://github.com/n64decomp/007>
- GoldenEye historical lineage: <https://gitlab.com/kholdfuzion/goldeneye_src>
- Harvest Moon 64: <https://github.com/harvestwhisperer/hm64-decomp>
- Hybrid Heaven: <https://github.com/ogdanimal/HybridHeaven-Decomp>
- Jet Force Gemini: <https://github.com/ryan-myers/jet-force-gemini>
- Kirby 64: <https://github.com/kirby64ret/kirby64>
- Mario Golf: <https://github.com/monde-lointain/mariogolf64>
- Mario Kart 64: <https://github.com/n64decomp/mk64>
- Mario Party: <https://github.com/mariopartyrd/marioparty>
- Mario Party 2: <https://github.com/mariopartyrd/marioparty2>
- Mario Party 3: <https://github.com/mariopartyrd/marioparty3>
- Mario Tennis: <https://github.com/dellm-79/mariotennisn64>
- Mischief Makers: <https://github.com/drahsid/mischief-makers>
- Mystical Ninja Starring Goemon: <https://github.com/klorfmorf/mnsg>
- Neon Genesis Evangelion: <https://github.com/farisawan-2000/evangelion>
- The New Tetris: <https://github.com/kiritodv/tnt>
- Onegai Monsters: <https://github.com/ryan-myers/onegaimonsters>
- Paper Mario: <https://github.com/pmret/papermario>
- Paperboy: <https://github.com/marijnvdwerf/paperboy-n64>
- Perfect Dark: <https://github.com/n64decomp/perfect_dark>
- Perfect Dark historical lineage: <https://gitlab.com/ryandwyer/perfect-dark>
- Pokemon Puzzle League: <https://github.com/angheloalf/puzzleleague64>
- Pokemon Snap: <https://github.com/ethteck/pokemonsnap>
- Pokemon Stadium: <https://github.com/pret/pokestadium>
- Pokemon Stadium 2: <https://github.com/pret/pokestadiumgs>
- Quest 64: <https://github.com/rainchus/quest64-decomp>
- Ridge Racer 64: <https://github.com/jvicu2001/rr64-decomp>
- Rocket: Robot on Wheels: <https://github.com/RocketRet/Rocket-Robot-On-Wheels>
- Shadowgate 64: <https://github.com/rainchus/shadowgate64>
- Snowboard Kids: <https://github.com/sonicdcer/sk>
- Snowboard Kids 2: <https://github.com/cdlewis/snowboardkids2-decomp>
- Space Station Silicon Valley: <https://github.com/mkst/sssv>
- Star Fox 64: <https://github.com/sonicdcer/sf64>
- Star Wars: Rogue Squadron: <https://github.com/Tmcg2/rogue_squadron64>
- Star Wars: Shadows of the Empire: <https://github.com/eltalelibrarian/sote>
- Super Mario 64: <https://github.com/n64decomp/sm64>
- Super Smash Bros.: <https://github.com/vetritheretri/ssb-decomp-re>
- Tube: <https://github.com/rep-stosw/tube64>
- Turok 3: <https://github.com/Drahsid/turok3>
- Virtual Pool 64: <https://github.com/llonsit/virtualpool64>
- Virtual Pro Wrestling 2: <https://github.com/aki-club/vpw2>
- Wave Race 64: <https://github.com/llonsit/wave-race-64>
- WCW Thunder: <https://github.com/martinbean/thunder>
- Wonder Project J2: <https://github.com/LLONSIT-glitch/wonder>
- Yoshi's Story: <https://github.com/decompals/yoshis-story>
- Rugrats: Scavenger Hunt, USA revision 0: <https://github.com/TheGh0stShip/Rugrats-Scavenger-Hunt>
- BattleTanx, USA revision 0: <https://github.com/TheGh0stShip/BattleTanx>
- BattleTanx: Global Assault, USA revision 0: <https://github.com/TheGh0stShip/BattleTanx-Global-Assault>

The completed Nagano project was independently verified in the registries but
its current canonical repository URL was not rediscovered. It remains a
resolved project with an unresolved present location. The historical Superman
repository is retained as external research evidence only and must never be
used as this repository's ancestry.

### Moved, deleted, and alternate lineages

- Majora's Mask moved from <https://github.com/n64decomp/majora> to
  <https://github.com/zeldaret/mm>.
- Mystical Ninja moved from the unavailable `Fluvian/mnsg` lineage to
  <https://github.com/klorfmorf/mnsg>.
- Banjo-Tooie moved from <https://github.com/wedarobi/banjo2> to
  <https://github.com/mr-wiseguy/banjo-tooie>.
- Goemon's Great Adventure at `Fluvian/gga`, San Francisco Rush 2049 at
  `cabi24/SFRush2049-decomp`, and WCW/nWo Revenge at `svinsmoke212/revenge`
  are documented historical projects whose endpoints were unavailable during
  the census.
- Paper Mario's older RetroReversing effort, the Ocarina N64DD support-code
  project, and the Shadows of the Empire prototype project are separate
  historical scopes, not duplicates of the retail projects.

### Deliberately separate comparison corpora

Static translation projects, native ports, clean-room rewrites, tools, and
symbol-only scaffolds can provide names, boundaries, behavior, and compiler
clues, but they do not count toward matching-source progress. Relevant
examples include Superman64Recomp, N64Recomp projects, Doom64-RE, Duke64-RE,
SpaghettiKart, PaperBoat, and Knife Edge reversing scaffolds. This distinction
is mandatory when importing evidence into function, data, and unit totals.

No independently verifiable source-reconstruction project was found on
Codeberg, SourceHut, or Bitbucket during this census. That is a statement about
the search result, not proof that those forges contain none. GitLab yielded
canonical or historically important Banjo-Kazooie, Donkey Kong 64, GoldenEye,
and Perfect Dark repositories.
