# Provenance

## Retail disassembly baseline

The initial retail split, linker script, symbols, and assembly were imported
with their Git history from `farisawan-2000/superman`, retail commit
`d20e93d74ed0a7117dcb932fc5f4ec1ceba7c59a`. The `provenance` remote retains
the upstream URL. This history is the provenance for inherited handwritten
assembly.

Generated assembly was re-extracted from the verified local ROM with the
vendored Splat revision. The extraction changed several equivalent branch
pseudoinstructions; the rebuilt bytes remain identical.

## Compiler tools

The Linux IRIX compiler recompilation binaries under `tools/ido/` were
imported from `n64decomp/mk64` commit
`58cfcb022e10f83bc3b889d7e97508cae6837098`. They are used to reproduce the
original compiler's code generation. The game builds matching code with the
MIPS II instruction scheduling mode.

## Converted source

Each assembly-to-C conversion is accepted only when the complete ROM passes
the SHA-1 gate in `superman.sha1`. The original assembly remains in history so
that instruction provenance and review remain available.

## libultra assembly

Low-level routines that directly access coprocessor registers remain in
assembly. Their canonical names and instruction sequences were verified
against `decompals/ultralib` commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`:

| ROM offset | Canonical symbol | Upstream source |
| --- | --- | --- |
| `0x0C4490` | `__osSetSR` | `src/os/setsr.s` |
| `0x0C44A0` | `__osGetSR` | `src/os/getsr.s` |
| `0x0C84B0` | `osGetCount` | `src/os/getcount.s` |
| `0x0CCDA0` | `sqrtf` | `src/gu/sqrtf.s` |
| `0x0CF930` | `__osSetCompare` | `src/os/setcompare.s` |

These routines are provenance-backed assembly because their semantics depend
on instructions that portable C cannot express precisely.

## Shared libc string unit

The `0x0CE070-0x0CE10F` unit is byte-identical to the established
`memcpy`/`strlen`/`strchr` unit in `TheGh0stShip/BattleTanx` commit
`75baab78f2065a6f59ed8f51cf6ac4d0f42f6ec9`. Its source and verified compiler
flags were adopted with the original SHA-256 match
`68696b567cdf60a5a58699ece48b7ee030a2d3ad4cc5525553abac922981ad1a`.

Two additional units are byte-identical to established BattleTanx sources:

| Superman range | Canonical routine | Upstream source | SHA-256 |
| --- | --- | --- | --- |
| `0x0CF940-0x0CF9BF` | byte-range copy | `src/libultra/al_copy.c` | `fbbd00a358ba9f6e6d467b5e9bc4cc4c42160ed2fa845082aec37f6d176aa733` |
| `0x0D3BE0-0x0D3C3F` | `alHeapDBAlloc` | `src/libultra/al_heap_alloc.c` | `89e229d53e59eb1f0001821d5e54accf59730a33c1d54f2963b2e02d05fe5413` |

The formatting-wrapper unit at `0x0CD0D0-0x0CD14F` follows the verified
`src/libultra/sprintf.c` implementation in `TheGh0stShip/BattleTanx` commit
`a486ea425f22f87acae291b2422d2c59b22650e2`. Its callback, variadic argument
cursor, terminator write, and IDO `-O3` flags reproduce the retail unit
exactly.

## Hardware-status predicates

The SI, SP, and DP status predicates at `0x0CE6D0`, `0x0CE700`, and
`0x0D3B60` follow the established volatile-register implementations in
`TheGh0stShip/Rugrats64` commit
`970beb763697053eded0513de0a05a55a9cfb2b0`. The corresponding upstream
sources are `src/runtime/si_status_active.c`,
`src/runtime/sp_dma_active.c`, and `src/runtime/dp_status_active.c`.
Explicit branch returns compiled with IDO `-O1` reproduce all three retail
units exactly.

The raw-I/O routines at `0x0C4070` and `0x0D3A60` are the release forms of
`src/libultra/os_pi_raw_read_io.c` and
`src/libultra/os_si_raw_write_io.c` from the same Rugrats64 commit. Debug
assertions are absent from these retail units. Their remaining volatile MMIO
operations compile byte-exactly with IDO `-O1`.

The DP next-buffer routine at `0x0D3AB0` follows
`src/runtime/set_dp_next_buffer.c` from the same Rugrats64 commit. Its
explicit `u64` size preserves the original aligned argument placement and
64-bit addition. A register-qualified status poll with IDO `-O1` reproduces
the retail unit exactly.

The audio-interface status predicate and SP program-counter setter at `0x0D4900` and
`0x0D4970` follow `src/runtime/audio_interface_status_negative.c` and
`src/runtime/set_sp_pc.c` from the same Rugrats64 commit. Together with the
adjacent protected getter, the complete `0x0D4900-0x0D49AF` unit compiles
byte-exactly with IDO `-O1`.

The raw SP DMA starter at `0x0C7630` follows
`src/runtime/start_sp_raw_dma.c` from the same Rugrats64 commit with retail
debug assertions absent. Along with its adjacent protected getter, the full
`0x0C75F0-0x0C76BF` unit compiles byte-exactly with IDO `-O1`.

The raw SI DMA starter at `0x0C4800` follows
`src/libultra/os_si_raw_start_dma.c` from the same Rugrats64 commit, with its
retail debug assertion absent. The release-form control flow is also present
in `TheGh0stShip/BattleTanx` commit
`a486ea425f22f87acae291b2422d2c59b22650e2`. Its busy check, cache operations,
physical-address conversion, and volatile SI register writes compile
byte-exactly with IDO `-O1`.

The raw SI read-I/O routine at `0x0C4980` follows
`src/libultra/os_si_raw_read_io.c` from the same BattleTanx commit. Its busy
check and uncached volatile load compile byte-exactly with IDO `-O1`. The
adjacent protected SI control update at `0x0C4910` is also matching C. The
type-zero queue wrapper at `0x0C49D0` uses the runtime-message layout described
below and compiles byte-exactly with IDO `-O2`.

The matrix concatenation and three-coordinate transform unit at
`0x0CCE70-0x0CD07F` follows
`src/runtime/matrix_concatenate.c` from the same Rugrats64 commit. The loop
nesting, temporary 4-by-4 matrix, final copy, and component-expression order
compile byte-exactly with IDO `-O3` when the source functions are ordered to
reproduce the retail section layout.

The type-1 and floating-point type-4 runtime command wrappers at `0x0C0A40`
and `0x0C84C0` were reconstructed from the verified retail disassembly
baseline. Their queue offset, active-record fields, and `0x30`-byte record
stride are corroborated by the adjacent type-2, type-3, and type-8 wrappers at
`0x0D0C00`, `0x0CDFD0`, and `0x0C48B0`. A cached record base and 16-byte
command view reproduce the retail scheduling byte-exactly with IDO `-O2`.

The active-record value getter at `0x0D0E10` was reconstructed from the
verified retail disassembly baseline. Its `0x30`-byte record stride agrees
with the runtime-command owner layout above, and its explicit 32-bit address
arithmetic preserves the target pointer-token semantics. The unrelated tail
beginning at `0x0D0E30`, including direct floating-point control-register
access, remains the provenance-backed retail assembly. The getter compiles
byte-exactly with IDO `-O2`.

The SP task-yield check at `0x0CEE20` follows
`src/runtime/check_sp_task_yielded.c` from `TheGh0stShip/Rugrats64` commit
`eda72c49741563c29ac4aba8d615d6fdce9c5f68`. Its status masks, yielded-result
calculation, and task-flag updates compile byte-exactly with IDO `-O1`. The
adjacent sound deallocator at `0x0CEEA0` follows `src/audio/sndpdeallocate.c`
from decompals/ultralib commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. Its release-mode state guard,
sound-pointer clear, and active-target reset compile byte-exactly with IDO
`-O2`.

The PI DMA submission routine at `0x0C8520` follows the release form of
`src/libultra/os_pi_start_dma.c` from `TheGh0stShip/BattleTanx` commit
`0fcb8c363c4dd75b7d50dfd96aa123dd4d5a0b47`. That source was reconstructed
against `decompals/ultralib` commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd` and verified as a complete IDO
object. Its manager check, message construction, and priority-dependent queue
dispatch compile byte-exactly for Superman with IDO `-O1`.

The VI initialization routine at `0x0D0390` follows
`src/libultra/os_vi.c` from `TheGh0stShip/BattleTanx` commit
`e43bd23032c2b8e9883673ffffbfb433df0b139b`. That complete object was likewise
reconstructed against the same `decompals/ultralib` commit. Its two-context
initialization, television-mode selection, current-line wait, and initial
context swap compile byte-exactly for Superman with IDO `-O1`.

The VI context-swap routine at `0x0D04D0` follows
`src/libultra/os_vi_swap_context.c` from the same BattleTanx commit and
canonical libultra revision. Its field selection, scale updates, complete VI
register programming sequence, pointer swap, and context copy compile
byte-exactly for Superman with IDO `-O1`.

The VI special-feature routine at `0x0D09D0` follows
`src/libultra/os_vi_set_special_features.c` from the same BattleTanx commit
and canonical libultra revision. Its interrupt protection and ordered gamma,
dither, divot, filter, and antialias control updates compile byte-exactly for
Superman with IDO `-O1`.

The extended PI raw DMA starter at `0x0CEBF0` follows
`src/libultra/os_epi_raw_start_dma.c` from `TheGh0stShip/BattleTanx` commit
`0fcb8c363c4dd75b7d50dfd96aa123dd4d5a0b47` and the same canonical libultra
revision. Its I/O-busy wait, domain timing cache, physical-address setup, and
direction-dependent transfer start compile byte-exactly for Superman with
IDO `-O1`.

The single-precision cosine routine at `0x0D0860` follows
`src/libultra/gu_cosf.c` from `TheGh0stShip/BattleTanx` commit
`ed81185e451219473fcbf230ed503c726516f210`, reconstructed against the same
canonical libultra revision. It reuses the retail coefficient, range-reduction,
zero, and quiet-NaN constants already present in the preserved data segment.
The complete routine compiles byte-exactly with IDO `-O3`.

The overlap-safe block-copy routine at `0x0CF9C0` is the handwritten libultra
`bcopy` implementation preserved as `src/libc/bcopy.s` in decompals/ultralib
commit `e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. Its forward and backward byte,
word, 16-byte, and 32-byte paths match the retail instruction stream. Because
the routine is upstream handwritten assembly rather than compiler output, it
remains an assembly unit with this provenance instead of being represented as
reconstructed C.

The pseudorandom-number generator at `0x0CD080` implements the algorithm from
`src/gu/random.c` in the same decompals/ultralib commit. Its retained seed at
`0x800DB120`, two adjacent multiplicands, unsigned multiply, and two-bit shift
identify `guRandom`. The seed is initialized to decimal `174823885`
(`0x0A6B99CD`) at ROM
`0x0DBD20`. The canonical source, with the seed as its function-local static,
compiles byte-exactly with IDO `-O2` and `-O3`; the unit uses `-O3`, matching
the graphics-utility objects that require it. The seed is visible to the
compiler through a non-load section at its retail RAM address; the inventoried
raw data block remains the sole owner of its ROM bytes.

The complete `0x0CD150-0x0CDE07` formatted-output object follows
`src/libc/xprintf.c` from decompals/ultralib commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. Its private conversion-field
formatter and public `_Printf` engine compile byte-exactly with IDO `-O3` and
unsigned characters. The object's padding strings, format tables, and switch
table are visible to the compiler through non-load sections at their retail
RAM addresses, while the inventoried raw data remains the sole owner of their
ROM bytes.

The complete `0x0D2B70-0x0D362F` floating-point formatting object follows
`src/libc/xldtob.c` from the same decompals/ultralib commit. Its field emitter,
floating-point classifier, and `_Ldtob` conversion routine compile together
byte-exactly with IDO `-O3` and unsigned characters. The compiler-visible
power table, text constants, and rounding constant are linked through a
non-load section at their retail RAM address, leaving the inventoried raw data
as the sole owner of the corresponding ROM bytes.

The `0x0D37C0-0x0D3A5F` integer formatting object follows
`src/libc/xlitob.c` from the same decompals/ultralib commit. Its `_Litob`
conversion routine compiles byte-exactly with IDO `-O3` and unsigned
characters, including the unit's trailing alignment. Its lowercase and
uppercase digit tables are linked through a non-load section at their retail
RAM address, while the raw data inventory remains the sole ROM owner.

Five small linked assembly entry points also match handwritten sources in
decompals/ultralib commit `e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`:
`osGetCount` at `0x0C84B0` follows `src/os/getcount.s`, `sqrtf` at `0x0CCDA0`
follows `src/gu/sqrtf.s`, `__osSetCompare` at `0x0CF930` follows
`src/os/setcompare.s`, and the adjacent `__osSetSR` and `__osGetSR` entry points
at `0x0C4490` follow `src/os/setsr.s` and `src/os/getsr.s`. Their coprocessor
transfers, required hazard no-op, floating-point square-root instruction, and
return delay slots match the retail instruction streams, so these units remain
provenance-backed assembly.

The cartridge handle initializer at `0x0CC5F0` follows the pre-J implementation
of `osCartRomInit` in `src/io/cartrominit.c` from decompals/ultralib commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. The `0xB0000000` base-address
sentinel, raw PI-domain read, timing-field extraction, transfer-info clear, and
interrupt-protected insertion into the PI handle list all match that source.
Defining the handle in the same translation unit while pinning its audited
runtime address reproduces the retail IDO register schedule and complete unit.

The 64DD handle initializer at `0x0CDE90` follows the pre-J implementation of
`osLeoDiskInit` in `src/io/leodiskinit.c` from decompals/ultralib commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. Its domain-two handle fields,
PI timing-register writes, transfer-info clear, interrupt-protected handle-list
insertion, and disk-handle publication reproduce the complete retail function.

Four cache-maintenance units are handwritten libultra assembly from
decompals/ultralib commit `e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`.
The routine at `0x0CE140` follows `src/os/invalicache.s`, `0x0CE1C0` follows
`src/os/invaldcache.s`, `0x0C3D60` follows `src/os/writebackdcache.s`, and
`0x0D3BB0` follows `src/os/writebackdcacheall.s`. Their cache-size cutovers,
line alignment, hit and index operations, overflow guards, and loop delay slots
match the respective upstream sources. They therefore remain
provenance-backed assembly rather than reconstructed C.

The interrupt-mask routine at `0x0C1610` is the handwritten libultra
`osSetIntMask` implementation from `src/os/setintmask.s` in decompals/ultralib
commit `e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. Its status-register mask,
global CPU/RCP mask recovery, lookup-table conversion, MI register write, and
coprocessor hazard no-ops match the upstream instruction stream.

The adjacent interrupt primitives at `0x0D0350` follow the pre-J variants of
`__osDisableInt` and `__osRestoreInt` in `src/os/interrupt.s` from the same
commit. The TLB address probe at `0x0C6860` likewise matches handwritten
`src/os/probetlb.s`, including EntryHi preservation, page-half selection,
valid-bit test, and physical-address reconstruction. These low-level routines
remain provenance-backed assembly.

The time query at `0x0CEEF0` follows `src/os/gettime.c` from
decompals/ultralib commit `e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`.
It samples the count register under interrupt protection, subtracts the base
counter, adds the elapsed ticks to the retained 64-bit current time with the
original carry sequence, and compiles byte-exactly with IDO `-O1`.

The extended PI raw-read routine at `0x0D2170` follows `src/io/epirawread.c`
from the same decompals/ultralib commit. Its I/O-busy wait, per-domain timing
cache synchronization, uncached device read, and result store compile
byte-exactly with IDO `-O1`.

The debug TLB mapping routine at `0x0D2310` is the handwritten libultra
`osMapTLBRdb` implementation from `src/os/maptlbrdb.s` in the same commit.
Its reserved TLB index, zero page mask, uncached debug-port mapping, CP0 hazard
spacing, EntryHi restoration, and two trailing zero words match the upstream
instruction stream. It therefore remains provenance-backed assembly.

The audio unit at `0x0CE310-0x0CE46F` follows `src/audio/save.c` and
`src/audio/synremoveplayer.c` from the same decompals/ultralib commit. Its
three entry points are `alSaveParam`, `alSavePull`, and `alSynRemovePlayer`.
The filter parameter cases, source callback, four audio command words, and
interrupt-protected player-list removal all compile byte-exactly with IDO
`-O2`. Preserving the packet-building expression shapes also preserves the
retail instruction schedule. This replaces the complete assembly unit at
`0x0CE310-0x0CE46F`.

The 64DD handle initializer at `0x0CDE90` follows
`src/libultra/os_leo_disk_init.c` from `TheGh0stShip/BattleTanx` commit
`0fcb8c363c4dd75b7d50dfd96aa123dd4d5a0b47`, reconstructed against the same
decompals/ultralib commit. Its domain-2 timing values, PI register writes,
transfer-info clear, interrupt-protected PI-table insertion, and published
disk handle identify the pre-J `osLeoDiskInit`. Defining the handle in its
original translation unit while pinning its audited address reproduces the
complete retail object.

The two empty callbacks immediately following that initializer at `0x0CDF90`
and `0x0CDFAC` were reconstructed from the verified retail disassembly. Each
retains an otherwise unused volatile local so IDO preserves the original
eight-byte frame and four argument-home stores. Together they compile
byte-exactly with IDO `-O1`, including the unit's two trailing zero words.

The auxiliary audio-bus pull routine at `0x0CA710` follows
`src/libultra/al_aux_bus_pull.c` from `TheGh0stShip/Rugrats64` commit
`f817a0db7e8ca1900cb47b0a3f4ea9bccf84a9aa`. Its two clear-buffer commands,
source-filter traversal, five-argument callback ABI, and returned command
cursor compile byte-exactly with IDO `-O3`.

The controller-pak identifier routine at `0x0CE470` follows pre-J `__osGetId`
in `src/io/contpfs.c` from decompals/ultralib commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. Its bank selection, identifier
checksum and repair flow, 32-byte copy, filesystem-layout derivation, and label
read reproduce the complete retail function and its trailing alignment.

The message-send and message-receive routines at `0x0BEAA0` and `0x0BED70`
follow `src/os/sendmesg.c` and `src/os/recvmesg.c` from the same
decompals/ultralib commit. Their interrupt-protected queue waits, circular
cursor updates, opposite-side thread wakeups, and nonblocking failure paths
compile byte-exactly with IDO `-O1` as `osSendMesg` and `osRecvMesg`.

The kernel-message unit at `0x0CE730-0x0CE97F` follows `src/os/jammesg.c`,
`src/os/setthreadpri.c`, and `src/os/getthreadpri.c` from decompals/ultralib
commit `e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. The first two routines are
`osJamMesg` and `osSetThreadPri` and both compile byte-exactly with IDO `-O1`.
The final null-aware priority getter at `0x0CE960` compiles byte-exactly with
IDO `-O2`, including its two trailing zero words.

The framebuffer-swap request at `0x0CE980` follows `src/io/viswapbuf.c` from
the same decompals/ultralib commit. Its interrupt-protected next-context
framebuffer update and buffer-dirty state bit compile byte-exactly with IDO
`-O1` as `osViSwapBuffer`.

The fixed-point position-matrix wrapper at `0x0CEB80` follows
`src/libultra/gu_position.c` from Rugrats64 commit
`f817a0db7e8ca1900cb47b0a3f4ea9bccf84a9aa`. Its stack matrix, call to the
floating-point builder, and final float-to-fixed conversion compile
byte-exactly with IDO `-O3`. The adjacent floating-point builder at
`0x0CE9D0` is `guPositionF` from `src/gu/position.c` in decompals/ultralib
commit `e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. Its canonical computation
also compiles byte-exactly with IDO `-O3`; the apparent global spill at
`0x80146C80` is the `-O3` placement of its initialized `dtor` static in
`.bss`, stored from `.rodata` on entry. Those sections are visible to the
compiler through non-load sections at their retail RAM addresses.

The runtime list helper at `0x0D0C60` masks interrupts through the existing
interrupt-control wrapper, copies the list's shared value into the new node,
prepends that node, and restores the prior mask. This compact translation
compiles byte-exactly with IDO `-O2`; it is project-specific runtime code and
does not rely on an upstream SDK identification.

The audio DAC frequency programmer at `0x0CF5C0` follows
`src/libultra/os_ai_set_frequency.c` from BattleTanx commit
`0fcb8c363c4dd75b7d50dfd96aa123dd4d5a0b47`. Its video-clock divisor,
minimum DAC-rate check, bit-rate clamp, hardware-register writes, and returned
effective frequency compile byte-exactly with IDO `-O1` as
`osAiSetFrequency`.

The vector normalizer at `0x0CF8A0` follows `src/gu/normalize.c` from
decompals/ultralib commit `e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`.
Its reciprocal-length calculation and three component updates compile
byte-exactly with IDO `-O2` as `guNormalize`.

The controller address and data CRC routines at `0x0CF720-0x0CF89F` follow
`src/libultra/os_cont_crc.c` from BattleTanx commit
`75baab78f2065a6f59ed8f51cf6ac4d0f42f6ec9`. Their feedback polynomials,
bit traversal, and final address mask compile together byte-exactly with IDO
`-O1` as `__osContAddressCrc` and `__osContDataCrc`.

The audio DMA-length reader at `0x0D2070` follows
`src/libultra/os_ai_get_length.c` from BattleTanx commit
`cf14c3771d62739faa9f6266bd2e91058e54ddff`. Its direct hardware-register
read compiles byte-exactly with IDO `-O1` as `osAiGetLength`.

The global interrupt-mask resetter at `0x0CFCD0` follows
`src/libultra/os_reset_global_int_mask.c` from BattleTanx commit
`2e4c6d2afaddcf670f90c2c4f94b65508cd3b2d2`. Its protected update preserves
the RCP mask bits and compiles byte-exactly with IDO `-O1` as
`__osResetGlobalIntMask`.

The audio-buffer submission routine at `0x0D4850` follows
`src/io/aisetnextbuf.c` from decompals/ultralib commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`, with the same pre-J hardware
workaround documented by BattleTanx commit
`21bab9906b7aabd216453461036722165ad5f97a`. Its queue-full check, physical
address conversion, and DAC register programming compile byte-exactly with
IDO `-O1` as `osAiSetNextBuffer`.

The fixed-point alignment-matrix wrapper at `0x0D4800` follows
`src/gu/align.c` from decompals/ultralib commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. Its temporary floating-point
matrix, `guAlignF` call, and final float-to-fixed conversion compile
byte-exactly with IDO `-O3` as `guAlign`.

Its floating-point builder at `0x0D4640` is the adjacent `guAlignF` from the
same decompals/ultralib source and commit. The normalized axis, degree
conversion, sine/cosine pair, horizontal-length guard, and matrix terms match
the canonical implementation, which compiles byte-exactly with IDO `-O3`. As
with `guPositionF` and `guRotateF`, the apparent global spill at `0x80147F00`
is the `-O3` placement of the initialized `dtor` static in `.bss`, and the
source's empty `else` branch has no code.

Likewise, the floating-point rotation builder at `0x0CF380` follows
`src/gu/rotate.c` from decompals/ultralib commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. Its normalized axis and
Rodrigues-style matrix terms identify `guRotateF`; the adjacent routine at
`0x0CF514` is its `guRotate` fixed-point wrapper. The pre-2.0K form of the
source, with each axis-sine product recomputed, compiles byte-exactly with IDO
`-O3` as the complete `0x0CF380-0x0CF56F` object, including its trailing
alignment padding. At `-O3` the compiler places the initialized `dtor` static
in `.bss` and stores its constant from `.rodata` on entry; this is the
apparent global spill at `0x80146CD0`. The same `-O3` object shape is
documented for the 2.0I `gu/rotate.o` by `src/libultra/gu_rotate.c` in the
BattleTanx: Global Assault decompilation, commit
`453a1011e27f438f5be4096fa119602fa6d53381`. Both sections are visible to the
compiler through non-load sections at their retail RAM addresses; the
inventoried raw data block remains the sole owner of the constant's ROM bytes.

The signed division helpers at `0x0D3630-0x0D37BF` follow `src/libc/ldiv.c`
from decompals/ultralib commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`, as independently verified in
BattleTanx commit `fce491566c542307137a889e5de27a28fc9bae85`. They return the
standard quotient/remainder structures and adjust a negative quotient when
its remainder is positive. Both `lldiv` and `ldiv` compile byte-exactly with
IDO `-O3`.

The thread-start routine at `0x0D3FA0` follows
`src/libultra/os_start_thread.c` from BattleTanx commit
`d20c0aa0f303bd7e3bcaa428308d9ea4b1fb4f32`. Its stopped and waiting state
transitions, queue repair, dispatch, and priority-based preemption compile
byte-exactly with IDO `-O1` as `osStartThread`.

The standard MIDI sequence object at `0x0C36C0-0x0C3CDF` follows
`src/libultra/al_seq.c` from BattleTanx commit
`ed81185e451219473fcbf230ed503c726516f210`, corresponding to
`src/audio/seq.c` in decompals/ultralib commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. Its location helpers,
compiler-retained private no-op, variable-length reader, event decoder,
marker constructor, time conversions, delta peek, endian-safe readers, and
sequence initializer compile together byte-exactly with IDO `-O3`. Keeping
the complete translation unit preserves the private-call allocation and
layout that isolated subsets could not reproduce. The two retail million
constants at `0x800DFBD0` and `0x800DFBD8` remain in the original data block.

The virtual-address translator at `0x0C3CE0` follows
`src/libultra/os_virtual_to_physical.c` from BattleTanx commit
`e43bd23032c2b8e9883673ffffbfb433df0b139b`, corresponding to
`src/os/virtualtophysical.c` in decompals/ultralib commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. Its direct KSEG0/KSEG1 masks
and TLB-probe fallback compile byte-exactly with IDO `-O1` as
`osVirtualToPhysical`.

The system bootstrap at `0x0C3DE0` follows
`src/libultra/os_initialize.c` from BattleTanx commit
`0fcb8c363c4dd75b7d50dfd96aa123dd4d5a0b47`, corresponding to
`src/os/initialize.c` in decompals/ultralib commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. Its status-register setup,
PIF handshake, exception-preamble installation, cache synchronization, TLB
initialization, reset-buffer clearing, and video-clock selection identify
`osInitialize` and compile byte-exactly with IDO `-O1`. Its canonical clock,
video-clock, shutdown, interrupt-mask, and final-ROM globals are visible to
the compiler through non-load sections at their retail RAM addresses; the
inventoried raw data block remains the sole owner of their ROM bytes.

The ten 64-bit helpers at `0x0C40D0-0x0C438F` follow
`src/libultra/ll.c` from BattleTanx commit
`75baab78f2065a6f59ed8f51cf6ac4d0f42f6ec9`, corresponding to
`src/libc/ll.c` in decompals/ultralib commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. They implement the signed and
unsigned shift, divide, remainder, multiply, adjusted modulo, and immediate
divide/remainder support routines. They remain provenance-backed assembly
because the project compiler's 32-bit MIPS2 mode calls these helpers when
the equivalent long-long expressions are compiled.

The runtime event wrapper at `0x0C44B0` constructs a type-17 event on the
stack and submits it to the owner's queue. It is project-specific code and
compiles byte-exactly with IDO `-O2`.

The runtime command wrapper at `0x0C67D0` allocates a command when the event
has an active object, timestamps it from the owner base and object offset,
stores a type-7 floating-point payload, and dispatches it through the object's
handler. It is project-specific code reconstructed from the verified retail
disassembly baseline and compiles byte-exactly with IDO `-O2`.

The scheduler-client insertion routine at `0x0C7180` follows
`src/runtime/add_scheduler_client.c` from `TheGh0stShip/Rugrats64` commit
`56eaca39999ed989f97ca34029cb4332ec148fd2`. Its interrupt protection and
head insertion into the scheduler's client list compile byte-exactly with IDO
`-O2`.

The scheduler command-queue getter and client-removal routine at
`0x0C70F0-0x0C717F` follow `osScGetCmdQ` and `osScRemoveClient` from
`src/sched/sched.c` in decompals/ultralib commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. Their command-queue offset,
interrupt protection, linked-list search, and head/interior removal paths
compile together byte-exactly with IDO `-O2`.

The scheduler constructor at `0x0C71D0` follows `osCreateScheduler` from the
same decompals/ultralib scheduler source. Its task and client-list resets,
message queues, video manager and event registration, scheduler-thread
creation, and thread start compile byte-exactly with IDO `-O2`.

The SP task-loading unit at `0x0C7300-0x0C75EF` follows
`src/libultra/os_sp_task.c` from BattleTanx commit
`ed81185e451219473fcbf230ed503c726516f210`, corresponding to
`src/io/sptask.c` in decompals/ultralib commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. The private physical-pointer
staging helper, `osSpTaskLoad`, and `osSpTaskStartGo` compile together
byte-exactly with IDO `-O1`, preserving their unaligned internal boundaries.

The runtime-list helper at `0x0C9940` caches the list's item-array pointer and,
for operation type 2, appends the supplied item and advances the count. It is
project-specific code reconstructed from the verified retail disassembly
baseline and compiles byte-exactly with IDO `-O2`.

The doubly linked-list helper at `0x0BEEB0` repairs the next node's previous
link and the previous node's next link when those neighbors exist. It is
project-specific code reconstructed from the verified retail disassembly
baseline and compiles byte-exactly with IDO `-O2`.

The adjacent block at `0x0BEEE0-0x0BEF6F` contains the complementary list
insertion helper and two lifecycle wrappers for a shared runtime owner. The
wrappers release an existing owner or initialize a previously empty owner.
These project-specific routines were reconstructed from the verified retail
disassembly baseline and compile together byte-exactly with IDO `-O2`.

The scale-matrix object at `0x0BEF70-0x0BF00F` follows `guScaleF` and
`guScale` from `src/gu/scale.c` in decompals/ultralib commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. The floating-point diagonal
builder and fixed-point conversion wrapper compile together byte-exactly with
IDO `-O3`.

The floating-point absolute-value helper at `0x0012A20` promotes its input to
double precision for the sign comparison, then returns either the negated or
original single-precision value. It is project-specific code reconstructed
from the verified retail disassembly baseline and compiles byte-exactly with
IDO `-O1`.

The runtime command wrapper at `0x0D24B0` allocates a command for an active
event object, records its type-13 parameters and timing value, and dispatches
it through the object's handler. It is project-specific code reconstructed
from the verified retail disassembly baseline and compiles byte-exactly with
IDO `-O2`.

The shared-control wrappers at `0x0C0830-0x0C08EF` initialize the underlying
state, lazily initialize and acquire it, or release it. These project-specific
routines were reconstructed from the verified retail disassembly baseline and
compile together byte-exactly with IDO `-O1`.

The event wrappers at `0x0C48B0`, `0x0CDFD0`, and `0x0D0C00` select the
owner's current runtime record, construct type-8, type-3, or type-2 events with
their respective byte or halfword payload, and submit them to the owner queue.
These project-specific routines were reconstructed from the verified retail
disassembly baseline and compile byte-exactly with IDO `-O3`.

The perspective-matrix routines at `0x0C44E0-0x0C476F` follow
`src/libultra/gu_perspective.c` from BattleTanx commit
`2e4c6d2afaddcf670f90c2c4f94b65508cd3b2d2`, corresponding to
`src/gu/perspective.c` in decompals/ultralib commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. The floating-point builder at
`0x0C44E0` compiles byte-exactly with IDO `-O2` as `guPerspectiveF`, including
its nested scale loop and perspective-normalization conversion. It reuses the
retail degree-to-radian constant at `0x800DFBE0`. The fixed-point wrapper at
`0x0C4710` compiles byte-exactly with IDO `-O3` as `guPerspective`.

The matrix utility object at `0x0C4F40-0x0C51AF` follows `src/gu/mtxutil.c`
from decompals/ultralib commit
`e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. `guMtxIdentF`, `guMtxIdent`,
and `guMtxL2F` are independently represented by BattleTanx commits
`06610320ff7caaaaf4ac4816cf1ca90d0466d824`,
`2e4c6d2afaddcf670f90c2c4f94b65508cd3b2d2`, and
`4c59c0296a955ecc07b4daee14b90c3690f318b6`. Compiling the three routines
together with the preceding `guMtxF2L` conversion preserves their unaligned
internal boundaries and matches the complete object byte-for-byte with IDO
`-O2`. The conversion scales each float to 16.16 fixed point and packs paired
integer and fractional halves into the retail matrix layout.

The controller-pak RAM-write object at `0x0D25A0-0x0D28FF` follows the
pre-J implementation of `src/io/contramwrite.c` from decompals/ultralib
commit `e24c836796df4bf520ff8b11a5c9d2cea3a66cbd`. Its public transfer routine
and private command-packet builder compile together byte-exactly with IDO
`-O1`, including the object's trailing alignment.

The adjacent PI write and timer objects at `0x0D2900-0x0D2B6F` follow
`src/io/epirawwrite.c` and the pre-K path of `src/os/settimer.c` from the same
ultralib revision. They compile byte-exactly with IDO `-O1`, including the
timer object's trailing alignment.

The controller-pak RAM-read object at `0x0D3C40-0x0D3F9F` follows the pre-J
implementation of `src/io/contramread.c` from the same ultralib revision. Its
public transfer routine and private command-packet builder compile together
byte-exactly with IDO `-O1`, including the object's trailing alignment.
