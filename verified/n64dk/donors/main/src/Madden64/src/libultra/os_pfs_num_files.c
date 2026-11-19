#include "pfs.h"

s32 osPfsNumFiles(OSPfs* pfs, s32* maxFiles, s32* filesUsed) {
    int index;
    s32 result;
    OSDir directory;
    int files = 0;

    if ((pfs->status & 1) == 0) {
        return 5;
    }
    if (__osCheckId(pfs) == 2) {
        return 2;
    }
    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        result = __osPfsSelectBank(pfs);
        if (result != 0) {
            return result;
        }
    }
    for (index = 0; index < pfs->dir_size; index++) {
        result = __osContRamRead(pfs->queue, pfs->channel,
                                 pfs->dir_table + index, (u8*)&directory);
        if (result != 0) {
            return result;
        }
        if (directory.company_code != 0 && directory.game_code != 0) {
            files++;
        }
    }
    *filesUsed = files;
    *maxFiles = pfs->dir_size;
    return 0;
}
