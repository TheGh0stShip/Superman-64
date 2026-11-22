# Superman 64

[![Matching code](https://bytematch.dev/TheGh0stShip/Superman-64.svg?version=NSPE&measure=matched_code_percent&label=Matching%20code)](https://bytematch.dev/TheGh0stShip/Superman-64/NSPE)
[![Matching functions](https://bytematch.dev/TheGh0stShip/Superman-64.svg?version=NSPE&measure=matched_functions_percent&label=Matching%20functions)](https://bytematch.dev/TheGh0stShip/Superman-64/NSPE)
[![Fully linked](https://bytematch.dev/TheGh0stShip/Superman-64.svg?version=NSPE&measure=complete_code_percent&label=Fully%20linked)](https://bytematch.dev/TheGh0stShip/Superman-64/NSPE)

Matching decompilation of the North American release of *Superman: The New
Superman Adventures* for Nintendo 64.

The required ROM is not distributed with this repository. Place a verified
big-endian ROM at `baserom.z64`. Its SHA-1 must be
`c271db752610c9581e1ba1e9125ea8ecdb56f74f`.

## Build

The build requires GNU Make, a MIPS GNU binutils toolchain, and a C compiler
capable of running the included IRIX compiler recompilation. Run `make`; a
successful build ends with:

```
build/superman.z64: OK
```

The SHA-1 check is the authoritative byte-match gate. ROM layout and source
history are recorded under `docs/`.

## Progress

Reviewed matching functions are published through the `NSPE_report` artifact
and displayed on [ByteMatch](https://bytematch.dev/TheGh0stShip/Superman-64).
Run `make report` to generate the same report locally without a ROM. Tracker
credit excludes inherited generated assembly; provenance-backed handwritten
assembly is recorded separately from compiler-generated C. See
[`docs/progress.md`](docs/progress.md) for the reporting policy and audited
denominators.

Current audited progress is **96,696 of 875,680 executable bytes (11.04%)**
and **516 of 1,056 functions (48.86%)** matched in C. Of that total, **96,484
bytes (11.02%) are fully linked** across two independently byte-identical
retail cartridge profiles. All 516 matched functions are consumed from C by at
least one exact profile. Only 212 trailing alignment bytes inside catalogued
function ranges remain raw, so they receive match credit but not linked credit.
The N64 Decomp Kit profile reproduces all 8,388,608 ROM bytes with the retail
SHA-1. See [`docs/n64dk-verification.md`](docs/n64dk-verification.md) for the
receipt and accounting rules.
