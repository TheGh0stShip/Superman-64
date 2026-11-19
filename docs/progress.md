# Progress reporting

The public progress report follows the objdiff v2 artifact contract used by
the Rugrats, Nagano, BattleTanx and BattleTanx: Global Assault matching
projects.

`config/us/functions.tsv` is the canonical retail function-body catalogue.
Its 1,056 entries account for 865,304 CPU function-body bytes. Function ends are
checked against retail disassembly; matching C entries are checked against
their emitted sizes. `config/us/nonfunction_ranges.tsv` separately accounts
for 1,516 bytes of alignment and embedded data within the CPU function range.
The physical ROM inventory additionally records non-function executable and
RSP text. The public code denominator is therefore the complete 875,680-byte
executable text inventory, not merely the sum of function bodies.

The 152 source units own 866,788 executable bytes. A complete source unit
receives credit for its emitted alignment as well as its matching functions;
the current 85 complete units therefore contribute 35,184 fully linked bytes.
An independently exact N64 Decomp Kit mixed cartridge profile links every
externally verified function. Across both profiles, 94,224 function-body bytes
and 664 bytes of linked complete-unit alignment produce 94,888 fully linked
bytes. The remaining 212 matched bytes are trailing alignment retained raw by
the mixed profile, for 95,100 matched code bytes overall.
The remaining executable inventory is shown
separately as 1,532 bytes of uncatalogued CPU text and 7,360 bytes of RSP text,
with no matching credit.

`config/us/matching_units.tsv` contains only compiler-generated C functions
whose bytes are already covered by the full-ROM SHA-1 build gate. Every row
records its ROM and VRAM address, emitted size, source path and source hash.
`config/us/verified_n64dk.tsv` separately records strict function-level C
recompilations. Those rows carry their compiler recipe or donor evidence and
point to immutable source copies under `verified/n64dk/`.
`config/us/linked_profiles.json` cryptographically binds that manifest to an
exact mixed-source cartridge relink. Its manifest-indexed bitmap grants linked
status to all 248 rows and records 47,772 linked source bytes; 212 trailing
alignment bytes remain raw. External profiles do not grant complete-unit
credit.
The report generator rejects stale hashes, duplicate or overlapping evidence,
noncanonical starts, mismatched body sizes, incomplete image accounting and
out-of-range entries.

The 152 resident code units come directly from the ordered subsection
boundaries in `superman.yaml`; match status and current filenames cannot change
their ownership or count. Generated assembly prefixes and suffixes are folded
into their intended `src/...c` unit and are never exposed as public unit names.
The report unit count is therefore exactly 152 and does not change when a
function is converted.

The aggregate data denominator is the 43,344 bytes of initialized `.data` and
`.rodata` in the loaded program image. Separate categories account for all ROM
bytes: executable code, initialized data, identified graphics, loader-referenced
payload, unknown payload, padding, and cartridge metadata. Preserving bytes in
a raw binary makes the ROM build exact but earns no code, data, or asset credit.

Inherited generated assembly is not matching progress. Handwritten assembly
is eligible only after its upstream origin is established in
`docs/provenance.md`; those units require a separate reviewed manifest.
Initialized-data and asset identification establish denominators and category
ownership but earn no matching credit until reconstructed representations have
their own reviewed manifests and exact rebuild gates.

Run `make report` to write `build/report.json`. The report tests lock the
audited totals, coverage, unit grouping and public metadata contract. CI
publishes the same file as
`NSPE_report`, using the supported ROM's serial as the ByteMatch version key.
