# Superman 64

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

Current audited progress is **95,100 of 875,680 executable bytes (10.86%)**
and **505 of 1,056 functions (47.82%)** matched in C. Of that total, 35,184
bytes across 85 source units are fully linked into the exact-ROM build. The
remaining function-level matches are strict recompilation results published
with their source, recipe or donor provenance, and hashes under
`verified/n64dk/`. ByteMatch reports linked and function-level progress
separately.
