# Progress reporting

The public progress report follows the objdiff v2 artifact contract used by
the Rugrats, Nagano and BattleTanx matching projects.

`config/us/functions.tsv` is the canonical retail function-body catalogue.
Its 1,050 entries account for 865,304 executable bytes. Function ends are
checked against retail disassembly; matching C entries are checked against
their emitted sizes. `config/us/nonfunction_ranges.tsv` separately accounts
for 1,432 bytes of alignment in the loaded text image. Those bytes preserve
address layout but are not functions and therefore do not inflate code
progress. Together the two ledgers cover ROM `0x1000` through `0xD49B0`
without gaps or overlaps.

`config/us/matching_units.tsv` contains only compiler-generated C functions
whose bytes are already covered by the full-ROM SHA-1 build gate. Every row
records its ROM and VRAM address, emitted size, source path and source hash.
The report generator rejects stale hashes, duplicate names, noncanonical
starts, mismatched body sizes, overlap, incomplete image accounting and
out-of-range entries.

Report units are grouped by their intended C source path (the translation-unit
model used by Nagano, BattleTanx and BattleTanx: Global Assault), rather than
inventing one unit for every function. Generated assembly prefixes and suffixes
are folded into the corresponding `src/...c` unit and are never exposed as
public unit names. Function counts and byte totals remain independent measures,
so a source containing several functions is represented as one unit with all
of its functions nested beneath it.

Inherited generated assembly is not matching progress. Handwritten assembly
is eligible only after its upstream origin is established in
`docs/provenance.md`; those units will be kept in a separate reviewed manifest
when added to the report. Initialized data and asset identification are also
excluded until their boundaries and formats have dedicated audited ledgers.

Run `make report` to write `build/report.json`. The report tests lock the
audited totals, coverage, unit grouping and public metadata contract. CI
publishes the same file as
`NSPE_report`, using the supported ROM's serial as the ByteMatch version key.
