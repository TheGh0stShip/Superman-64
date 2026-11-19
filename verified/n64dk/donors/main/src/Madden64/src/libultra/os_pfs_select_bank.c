#include "pfs.h"

s32 __osPfsSelectBank(OSPfs* pfs) {
    u8 data[32];
    int index;
    s32 result = 0;

    for (index = 0; index < 32; index++) {
        data[index] = pfs->activebank;
    }
    result = __osContRamWrite(pfs->queue, pfs->channel, 1024, data, 0);
    return result;
}
