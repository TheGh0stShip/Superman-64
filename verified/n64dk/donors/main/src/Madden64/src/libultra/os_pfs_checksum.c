#include "types.h"

u16 __osSumcalc(u8* bytes, s32 length) {
    s32 i;
    u32 sum = 0;
    u8* current = bytes;

    for (i = 0; i < length; i++) {
        sum += *current++;
        sum &= 0xFFFF;
    }
    return sum;
}

s32 __osIdCheckSum(u16* words, u16* checksum, u16* invertedChecksum) {
    u16 data = 0;
    u32 offset;

    *checksum = *invertedChecksum = 0;
    for (offset = 0; offset < 28; offset += 2) {
        data = *(u16*)((u32)words + offset);
        *checksum += data;
        *invertedChecksum += ~data;
    }
    return 0;
}
