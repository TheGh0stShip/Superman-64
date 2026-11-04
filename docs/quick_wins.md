# Quick wins

Leaf routines with no stack frame or external calls are the lowest-risk first
conversions. Current candidates, in order:

| ROM offset | Symbol | Behavior | Status |
| --- | --- | --- | --- |
| `0x001B90` | `func_80000F90` | initialize the shared six-field state | matching C (`-O2`) |
| `0x0035A0` | `func_800029A0` | dispatch three flag-selected runtime parameters | matching C (`-O1 -g3`) |
| `0x003680` | eight runtime dispatch/lifecycle helpers | map entries and manage shared runtime state | matching C (`-O1 -g3`) |
| `0x004CA0` | `func_800040A0` | parse decimal digits backward into an integer | matching C (`-O1 -g3`) |
| `0x004950` | four record-state helpers | activate records, set states, and update four runtime slots | matching C (`-O1 -g3`) |
| `0x004D60` | six string helpers | copy, bounded copy, concatenate, and compare strings | matching C (`-O1 -g3`) |
| `0x005070` | `func_80004470` | convert an ASCII string to lowercase in place | matching C (`-O1`) |
| `0x0050C0` | `func_800044C0` | convert an ASCII string to uppercase in place | matching C (`-O1`) |
| `0x00B1E0` | `func_8000A5E0` | scale two floating-point coordinates into integer output values | matching C (`-O1 -g3`) |
| `0x05AE70` | three vector helpers | dot product, construction, and copy | matching C (`-O2 -g3`) |
| `0x05B650` | `func_8005AA50` | multiply alternating descending integers as a float | matching C (`-O1 -g3`) |
| `0x00B5C0` | `func_8000A9C0` | flag a cell in the shared 31-column grid | matching C (`-O1 -g3`) |
| `0x00B630` | two grid dispatch helpers | emit an 11-by-11 region and derive horizontal bounds | matching C (`-O1 -g3`) |
| `0x012300` | `func_80011700` | compute and normalize an object-relative angular value | matching C (`-O1 -g3`) |
| `0x017F10` | `func_80017310` | normalize and clamp a motion-record value through runtime helpers | matching C (`-O1 -g3`) |
| `0x018390` | `func_80017790` | normalize and scale a motion-record angular value | matching C (`-O1 -g3`) |
| `0x019080` | `func_80018480` | validate and copy a linked runtime-object index | matching C (`-O1 -g3`) |
| `0x02BA10` | `func_8002AE10` | flag nearby linked runtime objects in states 2 and 3 | matching C (`-O1 -g3`) |
| `0x0350B0` | `func_800344B0` | traverse linked runtime objects and dispatch matching states | matching C (`-O1 -g3`) |
| `0x048CB0` | `func_800480B0` | find a linked runtime object by its field at offset `0x70` | matching C (`-O1 -g3`) |
| `0x0848E0` | `func_80083CE0` | store six floating-point configuration values | matching C (`-O2 -g3`) |
| `0x090710` | three threshold handlers | detect exceeded record thresholds and flag linked state | matching C (`-O1 -g3`) |
| `0x094770` | two event-state helpers | poll, clear, and configure the pending event | matching C (`-O1 -g3`) |
| `0x0A3D70` | `func_800A3170` | clear selected sentinel-terminated runtime records and set fixed flags | matching C (`-O1 -g3`) |
| `0x0C8AC0` | two runtime scaling helpers | empty callback and fixed-point scale/round/alignment | matching C (`-O2`) |
| `0x0C8B20` | three linked-list helpers | move nodes between runtime lists and prepend a node | matching C (`-O2`) |
| `0x0A4F20` | `func_800A4320` | empty callback | matching C |
| `0x0A4F28` | `func_800A4328` | empty callback | matching C |
| `0x0B7610` | `func_800B6A10` | zero-trip floating-point clearing loop | matching C (`-O1`) |
| `0x0B7970` | `func_800B6D70` | apply angle-derived offsets to sentinel-terminated track entries | matching C (`-O1 -g3`) |
| `0x0B7F00` | four runtime lookup/transform helpers | scan masked entries and apply paired quarter-turn transforms | matching C (`-O1 -g3`) |
| `0x0B9940` | `func_800B8D40` | clear active runtime entries up to the sentinel | matching C (`-O1 -g3`) |
| `0x0B9E00` | two runtime state setup helpers | select a state and update the active record | matching C (`-O1 -g3`) |
| `0x0B9EC0` | three event/state helpers | configure events and transition the active object | matching C (`-O1 -g3`) |
| `0x0BA000` | `func_800B9400` | flag the active entry in a two-dimensional runtime table | matching C (`-O1 -g3`) |
| `0x0B41D0` | `func_800B35D0` | reset shared state, allocate a handle, and select the next mode | matching C (`-O1 -g3`) |
| `0x0BD1D0` | three runtime state helpers | clear or flag ready states and dispatch them | matching C (`-O1 -g3`) |
| `0x0BEA10` | `func_800BDE10` | consume the next queued entry and advance shared queue state | matching C (`-O1 -g3`) |
| `0x0C0CB0` | `func_800C00B0` | empty callback | matching C |
| `0x0C0CB8` | `func_800C00B8` | empty callback | matching C |
| `0x0C2180` | `func_800C1580` | unlink an active node and return it to the free list | matching C (`-O2`) |
| `0x0C2400` | `func_800C1800` | acquire and initialize a node from a runtime free list | matching C (`-O2`) |
| `0x0C36B0` | `func_800C2AB0` | set a synthesizer voice priority | matching C (`-O2`) |
| `0x0C8BD0` | `func_800C7FD0` | pop and unlink the runtime-list head | matching C |
| `0x0D3BA0` | `func_800D2FA0` | read the SP status register | matching C |
| `0x0D3B90` | `func_800D2F90` | write the SP status register | matching C |
| `0x0D4500` | `func_800D3900` | return one global word | matching C |
| `0x0D4630` | `func_800D3A30` | clear one word through a pointer | matching C |
| `0x0D0E00` | `func_800D0200` | return a structure field | matching C |
| `0x0CD0B0` | `func_800CC4B0` | initialize a small structure | matching C |
| `0x0C51F0` | `func_800C45F0` | store a sign-extended field | matching C |
| `0x0D0830` | `func_800CFC30` | select a global value | matching C (`-O1`) |
| `0x0BED40` | `func_800BE140` | forward a pointer to a global owner | matching C |
| `0x0BFAE0` | `func_800BEEE0` | unlink a node from a singly linked list | matching C (`-O1`) |
| `0x0C04F0` | `func_800BF8F0` | initialize and perform the primary packed-record transfer | matching C (`-O1`) |
| `0x0C0660` | `func_800BFA60` | decode packed records and accumulate their valid-entry mask | matching C (`-O1`) |
| `0x0C0730` | `func_800BFB30` | initialize the primary packed-record array and append its sentinel | matching C (`-O1`) |
| `0x0C6490` | `func_800C5890` | retry, validate, and summarize the secondary packed-record transfer | matching C (`-O1`) |
| `0x0C6630` | `func_800C5A30` | initialize the secondary packed-record array and append its sentinel | matching C (`-O1`) |
| `0x0C6700` | `func_800C5B00` | decode the secondary packed-record array and accumulate its valid-entry mask | matching C (`-O1`) |
| `0x0CDE50` | `func_800CD250` | initialize an aligned buffer | matching C |
| `0x0CDE90` | `func_800CD290` | initialize the 64DD PI handle and timing registers | matching C (`-O1`) |
| `0x0CE070` | three libc string helpers | copy/length/search | matching C |
| `0x0CF940` | `func_800CED40` | copy a byte range | matching C |
| `0x0D3BE0` | `func_800D2FE0` | allocate from an audio heap | matching C |
| `0x0CE110` | `func_800CD510` | initialize a six-field state | matching C (`-O1`) |
| `0x0CE6D0` | `func_800CDAD0` | test SI status bits | matching C (`-O1`) |
| `0x0CE700` | `func_800CDB00` | test SP status bits | matching C (`-O1`) |
| `0x0D3B60` | `func_800D2F60` | test DP status bit | matching C (`-O1`) |
| `0x0C4070` | `func_800C3470` | raw PI word read | matching C (`-O1`) |
| `0x0D3A60` | `func_800D2E60` | raw SI word write | matching C (`-O1`) |
| `0x0D3AB0` | `func_800D2EB0` | set the DP next buffer | matching C (`-O1`) |
| `0x0CF570` | `func_800CE970` | update an interrupt-protected mask | matching C (`-O1`) |
| `0x0D2370` | `func_800D1770` | transition the active request state | matching C (`-O1`) |
| `0x0D0B90` | `func_800CFF90` | update three protected state fields | matching C (`-O1`) |
| `0x0C76C0` | `func_800C6AC0` | invoke the fixed-size helper | matching C (`-O1`) |
| `0x0C76E0` | `func_800C6AE0` | initialize protected source state | matching C (`-O1`) |
| `0x0D4900` | `func_800D3D00` | test the audio-interface status sign bit | matching C (`-O1`) |
| `0x0D4930` | `func_800D3D30` | read a protected state field | matching C (`-O1`) |
| `0x0D4970` | `func_800D3D70` | set the SP program counter | matching C (`-O1`) |
| `0x0C75F0` | `func_800C69F0` | read a protected state field | matching C (`-O1`) |
| `0x0C7630` | `func_800C6A30` | start raw SP DMA | matching C (`-O1`) |
| `0x0CD0D0` | `func_800CC4D0` | formatting output callback | matching C (`-O3`) |
| `0x0CD0F4` | `func_800CC4F4` | formatted string wrapper | matching C (`-O3`) |
| `0x0D4510` | `func_800D3910` | allocate and initialize a runtime slot | matching C (`-O2`) |
| `0x0D45B0` | `func_800D39B0` | construct and dispatch a runtime command | matching C (`-O2`) |
| `0x0C4770` | `func_800C3B70` | dispatch a type-14 runtime command | matching C (`-O2`) |
| `0x0C6920` | `func_800C5D20` | dispatch a type-12 byte command | matching C (`-O2`) |
| `0x0CE270` | `func_800CD670` | dispatch a type-16 magnitude command | matching C (`-O2`) |
| `0x0C4800` | `func_800C3C00` | start raw SI DMA | matching C (`-O1`) |
| `0x0C4910` | `func_800C3D10` | update the protected SI control flag | matching C (`-O1`) |
| `0x0C4980` | `func_800C3D80` | perform raw SI read I/O | matching C (`-O1`) |
| `0x0CCDB0` | `func_800CC1B0` | copy and update a transform | matching C (`-O2`) |
| `0x0CCE10` | `func_800CC210` | combine copied transforms | matching C (`-O2`) |
| `0x0CCE70` | `func_800CC270` | transform a three-component position | matching C (`-O3`) |
| `0x0CCF10` | `func_800CC310` | concatenate 4-by-4 matrices | matching C (`-O3`) |
| `0x0C0A40` | `func_800BFE40` | dispatch a type-1 runtime command | matching C (`-O2`) |
| `0x0C0830` | `func_800BFC30` | initialize the shared runtime control | matching C (`-O1`) |
| `0x0C0880` | `func_800BFC80` | lazily initialize and acquire the shared control | matching C (`-O1`) |
| `0x0C08C4` | `func_800BFCC4` | release the shared runtime control | matching C (`-O1`) |
| `0x0C84C0` | `func_800C78C0` | dispatch a type-4 floating-point command | matching C (`-O2`) |
| `0x0D0E10` | `func_800D0210` | read the active runtime-record value | matching C (`-O2`) |
| `0x0CEE20` | `func_800CE220` | check whether an SP task yielded | matching C (`-O1`) |
| `0x0C8520` | `func_800C7920` | submit a PI DMA request | matching C (`-O1`) |
| `0x0D0390` | `func_800CF790` | initialize the VI contexts | matching C (`-O1`) |
| `0x0D04D0` | `func_800CF8D0` | program and swap the VI context | matching C (`-O1`) |
| `0x0D09D0` | `func_800CFDD0` | update VI special features | matching C (`-O1`) |
| `0x0CEBF0` | `func_800CDFF0` | start an extended PI raw DMA transfer | matching C (`-O1`) |
| `0x0D0860` | `func_800CFC60` | compute single-precision cosine | matching C (`-O3`) |
| `0x0CF9C0` | `func_800CEDC0` | overlap-safe libultra block copy | provenance-backed assembly |
| `0x0CD080` | `func_800CC480` | libultra pseudorandom-number generator | matching C (`-O3`) |
| `0x0C84B0` | `osGetCount` | read the coprocessor count register | provenance-backed assembly |
| `0x0CCDA0` | `sqrtf` | single-precision square root | provenance-backed assembly |
| `0x0CF930` | `__osSetCompare` | write the coprocessor compare register | provenance-backed assembly |
| `0x0C4490` | `__osSetSR` / `__osGetSR` | write and read the coprocessor status register | provenance-backed assembly |
| `0x0C49D0` | `func_800C3DD0` | dispatch a type-0 runtime command with a caller flag | matching C (`-O2`) |
| `0x0C48B0` | `func_800C3CB0` | submit a type-8 byte event for the current record | matching C (`-O3`) |
| `0x0CDFD0` | `func_800CD3D0` | submit a type-3 halfword event for the current record | matching C (`-O3`) |
| `0x0D0C00` | `func_800D0000` | submit a type-2 byte event for the current record | matching C (`-O3`) |
| `0x0D23C0` | `func_800D17C0` | initialize a translated floating-point transform | matching C (`-O2`) |
| `0x0D2408` | `func_800D1808` | build and export a translated transform | matching C (`-O2`) |
| `0x0D2080` | `func_800D1480` | send a type-15 runtime message | matching C (`-O2`) |
| `0x0D20B0` | `func_800D14B0` | copy a bounded runtime text field | matching C (`-O1`) |
| `0x0CC6F0` | `func_800CBAF0` | initialize and clear the shared runtime queue | matching C (`-O2`) |
| `0x0CC740` | `func_800CBB40` | lazily initialize and receive from the shared queue | matching C (`-O2`) |
| `0x0CC784` | `func_800CBB84` | clear the shared runtime queue | matching C (`-O2`) |
| `0x0CC5F0` | `func_800CB9F0` | initialize the libultra cartridge handle | matching C (`-O1`) |
| `0x0CE140` | `func_800CD540` | invalidate an instruction-cache range | provenance-backed assembly |
| `0x0CE1C0` | `func_800CD5C0` | invalidate a data-cache range | provenance-backed assembly |
| `0x0C3D60` | `func_800C3160` | write back a data-cache range | provenance-backed assembly |
| `0x0D3BB0` | `func_800D2FB0` | write back the complete data cache | provenance-backed assembly |
| `0x0CA6E0` | `func_800C9AE0` | conditionally register a runtime child | matching C (`-O2`) |
| `0x0D2460` | `func_800D1860` | raise a fixed scale factor to an integer power | matching C (`-O2`) |
| `0x0D24B0` | `func_800D18B0` | construct and dispatch a type-13 runtime command | matching C (`-O2`) |
| `0x0C1610` | `func_800C0A10` | set and return the interrupt mask | provenance-backed assembly |
| `0x0D0350` | `func_800CF750` / `func_800CF770` | disable and restore interrupts | provenance-backed assembly |
| `0x0C6860` | `func_800C5C60` | probe the TLB for a physical address | provenance-backed assembly |
| `0x0CEEA0` | `func_800CE2A0` | deallocate a stopped sound-player slot | matching C (`-O2`) |
| `0x0CEEF0` | `func_800CE2F0` | return the current libultra system time | matching C (`-O1`) |
| `0x0D2170` | `func_800D1570` | read a word through an extended PI handle | matching C (`-O1`) |
| `0x0D2310` | `func_800D1710` | map the remote-debug port in the TLB | provenance-backed assembly |
| `0x0CE310` | `func_800CD710` | update an audio-save filter parameter | matching C (`-O2`) |
| `0x0CE344` | `func_800CD744` | emit audio-save commands | matching C (`-O2`) |
| `0x0CE3D0` | `func_800CD7D0` | remove a player from the synthesizer | matching C (`-O2`) |
| `0x0CDE90` | `func_800CD290` | initialize the pre-J 64DD PI handle | matching C (`-O1`) |
| `0x0CDF90` | `func_800CD390` | empty four-argument callback | matching C (`-O1`) |
| `0x0CDFAC` | `func_800CD3AC` | empty four-argument callback | matching C (`-O1`) |
| `0x0CA710` | `func_800C9B10` | pull commands from the auxiliary audio bus | matching C (`-O3`) |
| `0x0CE470` | `func_800CD870` | read and validate the controller-pak identifier | matching C (`-O1`) |
| `0x0BEAA0` | `func_800BDEA0` | send a kernel message | matching C (`-O1`) |
| `0x0BED70` | `func_800BE170` | receive a kernel message | matching C (`-O1`) |
| `0x0CE730` | `func_800CDB30` | prepend a kernel message | matching C (`-O1`) |
| `0x0CE880` | `func_800CDC80` | set a thread priority | matching C (`-O1`) |
| `0x0CE960` | `func_800CDD60` | get a thread priority | matching C (`-O2`) |
| `0x0CE980` | `func_800CDD80` | request a VI framebuffer swap | matching C (`-O1`) |
| `0x0CE9D0` | `func_800CDDD0` | build a floating-point position matrix | matching C (`-O3`) |
| `0x0CEB80` | `func_800CDF80` | build and convert a fixed-point position matrix | matching C (`-O3`) |
| `0x0D0C60` | `func_800D0060` | insert a node while interrupts are masked | matching C (`-O2`) |
| `0x0CF5C0` | `func_800CE9C0` | program the audio DAC frequency | matching C (`-O1`) |
| `0x0CF8A0` | `func_800CECA0` | normalize a three-component vector | matching C (`-O2`) |
| `0x0CF720` | `func_800CEB20` | compute a controller address CRC | matching C (`-O1`) |
| `0x0CF7D0` | `func_800CEBD0` | compute a controller data CRC | matching C (`-O1`) |
| `0x0D2070` | `func_800D1470` | read the pending audio DMA length | matching C (`-O1`) |
| `0x0CFCD0` | `func_800CF0D0` | reset selected global interrupt-mask bits | matching C (`-O1`) |
| `0x0D4850` | `func_800D3C50` | submit the next audio DMA buffer | matching C (`-O1`) |
| `0x0D4800` | `func_800D3C00` | build and convert a fixed-point alignment matrix | matching C (`-O3`) |
| `0x0D4640` | `func_800D3A40` | build a floating-point alignment matrix | matching C (`-O3`) |
| `0x0CF380` | `func_800CE780` | build a floating-point rotation matrix | matching C (`-O3`) |
| `0x0CF514` | `func_800CE914` | build and convert a fixed-point rotation matrix | matching C (`-O3`) |
| `0x0D3630` | `func_800D2A30` | return an adjusted 64-bit quotient and remainder | matching C (`-O3`) |
| `0x0D3730` | `func_800D2B30` | return an adjusted signed quotient and remainder | matching C (`-O3`) |
| `0x0D3FA0` | `func_800D33A0` | start a kernel thread and preempt when needed | matching C (`-O1`) |
| `0x0D40F0` | `func_800D34F0` | initialize and register a 76-byte runtime record | behavior and structure identified; `-O1` allocation pending |
| `0x0C36C0` | `func_800C2AC0` | save the current standard MIDI sequence location | matching C (`-O1`) |
| `0x0C36DC` | `func_800C2ADC` | restore a standard MIDI sequence location | matching C (`-O1`) |
| `0x0C36F8` | `func_800C2AF8` | return the current standard MIDI sequence tick | matching C (`-O1`) |
| `0x0C3CE0` | `func_800C30E0` | translate a virtual address to a physical address | matching C (`-O1`) |
| `0x0C36C0` | standard MIDI sequence object | parse events, markers, deltas, and headers | matching C (`-O3`) |
| `0x0C3DE0` | `func_800C31E0` | initialize the operating-system hardware state | matching C (`-O1`) |
| `0x0C40D0` | ten 64-bit compiler helpers | shifts, division, remainder, multiplication | canonical `ll.c`; provenance-backed assembly |
| `0x0C44B0` | `func_800C38B0` | submit a type-17 runtime event | matching C (`-O2`) |
| `0x0C4710` | `func_800C3B10` | build and convert a fixed-point perspective matrix | matching C (`-O3`) |
| `0x0C44E0` | `func_800C38E0` | build a floating-point perspective matrix | matching C (`-O2`) |
| `0x0C5040` | `func_800C4440` | build a floating-point identity matrix | matching C (`-O2`) |
| `0x0C50C8` | `func_800C44C8` | build a fixed-point identity matrix | matching C (`-O2`) |
| `0x0C50F8` | `func_800C44F8` | convert a fixed-point matrix to floating point | matching C (`-O2`) |
| `0x0C4F40` | `func_800C4340` | convert a floating-point matrix to fixed point | matching C (`-O2`) |
| `0x0C67D0` | `func_800C5BD0` | dispatch a type-7 floating-point command | matching C (`-O2`) |
| `0x0C70F0` | `func_800C64F0` | return the scheduler command queue | matching C (`-O2`) |
| `0x0C70F8` | `func_800C64F8` | remove a protected scheduler client | matching C (`-O2`) |
| `0x0C7180` | `func_800C6580` | prepend a protected scheduler client | matching C (`-O2`) |
| `0x0C71D0` | `func_800C65D0` | initialize and start the scheduler | matching C (`-O2`) |
| `0x0C7300` | `func_800C6700` | stage an SP task with physical pointers | matching C (`-O1`) |
| `0x0C741C` | `func_800C681C` | load an SP task and its boot program | matching C (`-O1`) |
| `0x0C75AC` | `func_800C69AC` | start a loaded SP task | matching C (`-O1`) |
| `0x0C9940` | `func_800C8D40` | conditionally append a runtime-list item | matching C (`-O2`) |
| `0x0BEEB0` | `func_800BE2B0` | unlink a node from a doubly linked list | matching C (`-O2`) |
| `0x0BEEE0` | `func_800BE2E0` | insert a node after a list anchor | matching C (`-O2`) |
| `0x0BEF04` | `func_800BE304` | release the shared runtime owner | matching C (`-O2`) |
| `0x0BEF3C` | `func_800BE33C` | initialize the shared runtime owner once | matching C (`-O2`) |
| `0x0BEF70` | `func_800BE370` | build a floating-point scale matrix | matching C (`-O3`) |
| `0x0BEFC4` | `func_800BE3C4` | build a fixed-point scale matrix | matching C (`-O3`) |
| `0x0012A20` | `func_80011E20` | return a floating-point absolute value | matching C (`-O1`) |

After these leaf routines, adjacent SDK-style cache and hardware-register
helpers should be identified against established libultra implementations
before conversion so their names and types retain upstream provenance.
