#include "pfs.h"

static s32 clearPage(OSPfs* pfs, int page, u8* data, u8 bank);

s32 __osPfsDeclearPage(OSPfs* pfs, OSInode* inode, int pageCount,
                       int* firstPage, u8 bank, int* allocated,
                       int* lastPage) {
    int index;
    int startPage;
    int oldPage;
    u8 data[32];
    int byteIndex;
    s32 result = 0;
    int offset = bank > 0 ? 1 : pfs->inode_start_page;

    for (index = offset; index < 128; index++) {
        if (inode->inode_page[index].ipage == 3) {
            break;
        }
    }
    if (index == 128) {
        *firstPage = -1;
        return result;
    }
    for (byteIndex = 0; byteIndex < 32; byteIndex++) {
        data[byteIndex] = 0;
    }
    startPage = index;
    *allocated = 1;
    oldPage = index;
    index++;
    while (pageCount > *allocated && index < 128) {
        if (inode->inode_page[index].ipage == 3) {
            inode->inode_page[oldPage].inode.bank = bank;
            inode->inode_page[oldPage].inode.page = index;
            result = clearPage(pfs, oldPage, data, bank);
            if (result != 0) {
                return result;
            }
            oldPage = index;
            (*allocated)++;
        }
        index++;
    }
    *firstPage = startPage;
    if (index == 128 && pageCount > *allocated) {
        *lastPage = oldPage;
        return result;
    }
    inode->inode_page[oldPage].ipage = 1;
    result = clearPage(pfs, oldPage, data, bank);
    *lastPage = 0;
    return result;
}

static s32 clearPage(OSPfs* pfs, int page, u8* data, u8 bank) {
    int index;
    s32 result;

    result = 0;
    pfs->activebank = bank;
    result = __osPfsSelectBank(pfs);
    if (result != 0) {
        return result;
    }
    for (index = 0; index < 8; index++) {
        result = __osContRamWrite(pfs->queue, pfs->channel,
                                  page * 8 + index, data, 0);
        if (result != 0) {
            break;
        }
    }
    pfs->activebank = 0;
    result = __osPfsSelectBank(pfs);
    return result;
}
