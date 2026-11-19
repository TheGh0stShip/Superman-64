#include "pfs.h"

s32 __osCheckPackId(OSPfs* pfs, OSPackId* id) {
    u16 addresses[4];
    s32 result = 0;
    u16 checksum;
    u16 invertedChecksum;
    int index;
    int copy;

    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        result = __osPfsSelectBank(pfs);
        if (result != 0) {
            return result;
        }
    }
    addresses[0] = 1;
    addresses[1] = 3;
    addresses[2] = 4;
    addresses[3] = 6;
    for (index = 1; index < 4; index++) {
        result = __osContRamRead(pfs->queue, pfs->channel,
                                 addresses[index], (u8*)id);
        if (result != 0) {
            return result;
        }
        __osIdCheckSum((u16*)id, &checksum, &invertedChecksum);
        if (id->checksum == checksum &&
            id->inverted_checksum == invertedChecksum) {
            break;
        }
    }
    if (index == 4) {
        return 10;
    }
    for (copy = 0; copy < 4; copy++) {
        if (copy != index) {
            result = __osContRamWrite(pfs->queue, pfs->channel,
                                      addresses[copy], (u8*)id, 1);
            if (result != 0) {
                return result;
            }
        }
    }
    return 0;
}
