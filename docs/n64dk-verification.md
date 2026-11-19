# N64 Decomp Kit verification evidence

`verified/n64dk/` contains strict function-level C evidence exported from an
unattended N64 Decomp Kit run of the supported North American ROM. It is kept
outside the normal build because these functions have not yet been integrated
into their original translation units.

Each credited row in `config/us/verified_n64dk.tsv` records the canonical ROM
and VRAM range, source path, SHA-256 digest, and the exact compiler recipe or
donor unit that reproduced the retail bytes. Rows marked `exact` were compiled
from an independently generated draft. Rows marked `donor` were compiled from
a source unit taken from another matching N64 project or a reconstructed SDK
library and then verified at Superman 64's addresses.

This evidence changes only function-level matching progress. It does not make
a source unit complete, does not increase the fully linked measure, and does
not replace the repository's authoritative full-ROM SHA-1 build gate. Moving a
function into the linked build requires review in its owning translation unit,
after which its external row must be removed and its linked row added to
`config/us/matching_units.tsv`.

The imported donor paths preserve their source-project identity. The current
evidence includes material verified from BattleTanx, Madden 64, Rugrats,
Nagano, Pilotwings 64, and reconstructed Nintendo 64 SDK units. Their presence
is evidence of byte identity, not a claim that those projects authored the
original Superman 64 source.
