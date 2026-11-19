#include "pfs.h"

s32 __osCheckId(OSPfs* pfs) {
    int index;
    u8 data[32];
    s32 result;

    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        result = __osPfsSelectBank(pfs);
        if (result != 0) {
            return result;
        }
    }
    result = __osContRamRead(pfs->queue, pfs->channel, 1, data);
    if (result != 0) {
        if (result != 2) {
            return result;
        }
        result = __osContRamRead(pfs->queue, pfs->channel, 1, data);
        if (result != 0) {
            return result;
        }
    }
    for (index = 0; index < 32; index++) {
        if (pfs->id[index] != data[index]) {
            return 2;
        }
    }
    return 0;
}
