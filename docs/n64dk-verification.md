# N64 Decomp Kit verification evidence

`verified/n64dk/` contains strict function-level C evidence exported from an
unattended N64 Decomp Kit run of the supported North American ROM. The sources
remain outside the conventional translation units, but a second mixed-source
link profile consumes the buildable subset directly.

Each credited row in `config/us/verified_n64dk.tsv` records the canonical ROM
and VRAM range, source path, SHA-256 digest, and the exact compiler recipe or
donor unit that reproduced the retail bytes. Rows marked `exact` were compiled
from an independently generated draft. Rows marked `donor` were compiled from
a source unit taken from another matching N64 project or a reconstructed SDK
library and then verified at Superman 64's addresses.

`config/us/linked_profiles.json` records the mixed profile's immutable proof:
the retail ROM SHA-1, zero differing bytes, linked-source byte totals, hashes
of the N64DK manifest and relink receipts, and a manifest-indexed bitmap of the
functions actually linked. The profile links all 250 externally verified
functions, including donor C, and contributes 48,000 source-linked bytes.
Because 53 canonical catalogue ranges include trailing alignment, 212 bytes at
their ends remain raw and do not receive linked credit. The complete cartridge
contains 85,760 linked text bytes and 1,968 linked data bytes across all images and is exactly
8,388,608 bytes with retail SHA-1
`c271db752610c9581e1ba1e9125ea8ecdb56f74f`.

This profile does not make an original translation unit complete. Complete-unit
credit remains restricted to the conventional build; linked-byte credit may
come from either independently exact cartridge profile. The report generator
refuses the external link receipt if the manifest changes, its bitmap totals do
not reconcile, or its ROM identity/exactness fields are not strict.

The imported donor paths preserve their source-project identity. The current
evidence includes material verified from BattleTanx, Madden 64, Rugrats,
Nagano, Pilotwings 64, and reconstructed Nintendo 64 SDK units. Their presence
is evidence of byte identity, not a claim that those projects authored the
original Superman 64 source.
