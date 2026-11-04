# Progress reporting

The public progress report follows the objdiff v2 artifact contract used by
the Rugrats, Nagano and BattleTanx matching projects.

`config/us/functions.tsv` is the canonical retail function catalogue. Its
ranges cover the complete linked program image from ROM `0x1000` through
`0xD49B0` without gaps or overlaps. This conservative code denominator also
includes alignment and unidentified in-text ranges until they are reviewed
and classified more precisely.

`config/us/matching_units.tsv` contains only compiler-generated C functions
whose bytes are already covered by the full-ROM SHA-1 build gate. Every row
records its ROM and VRAM address, emitted size, source path and source hash.
The report generator rejects stale hashes, duplicate names, noncanonical
starts, overlap and out-of-range entries.

Inherited generated assembly is not matching progress. Handwritten assembly
is eligible only after its upstream origin is established in
`docs/provenance.md`; those units will be kept in a separate reviewed manifest
when added to the report. Initialized data and asset identification are also
excluded until their boundaries and formats have dedicated audited ledgers.

Run `make report` to write `build/report.json`. CI publishes the same file as
`NSPE_report`, using the supported ROM's serial as the ByteMatch version key.
