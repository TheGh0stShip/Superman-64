#include "pfs.h"

s32 __osPfsRWInode(OSPfs* pfs, OSInode* inode, u8 flag, u8 bank) {
    u8 checksum;
    int block;
    s32 result;
    int offset;
    u8* address;

    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        result = __osPfsSelectBank(pfs);
        if (result != 0) {
            return result;
        }
    }
    offset = bank > 0 ? 1 : pfs->inode_start_page;
    if (flag == 1) {
        inode->inode_page[0].inode.page =
            __osSumcalc((u8*)&inode->inode_page[offset],
                        (128 - offset) * 2);
    }
    for (block = 0; block < 8; block++) {
        address = (u8*)inode->inode_page + block * 32;
        if (flag == 1) {
            result = __osContRamWrite(pfs->queue, pfs->channel,
                                      pfs->inode_table + bank * 8 + block,
                                      address, 0);
            result = __osContRamWrite(pfs->queue, pfs->channel,
                                      pfs->minode_table + bank * 8 + block,
                                      address, 0);
        } else {
            result = __osContRamRead(pfs->queue, pfs->channel,
                                     pfs->inode_table + bank * 8 + block,
                                     address);
        }
        if (result != 0) {
            return result;
        }
    }
    if (flag == 0) {
        checksum = __osSumcalc((u8*)&inode->inode_page[offset],
                               (128 - offset) * 2);
        if (checksum != inode->inode_page[0].inode.page) {
            for (block = 0; block < 8; block++) {
                address = (u8*)inode->inode_page + block * 32;
                result = __osContRamRead(
                    pfs->queue, pfs->channel,
                    pfs->minode_table + bank * 8 + block, address);
            }
            if (checksum != inode->inode_page[0].inode.page) {
                return 3;
            }
            for (block = 0; block < 8; block++) {
                address = (u8*)inode->inode_page + block * 32;
                result = __osContRamWrite(
                    pfs->queue, pfs->channel,
                    pfs->inode_table + bank * 8 + block, address, 0);
            }
        } else {
            for (block = 0; block < 8; block++) {
                address = (u8*)inode->inode_page + block * 32;
                result = __osContRamWrite(
                    pfs->queue, pfs->channel,
                    pfs->minode_table + bank * 8 + block, address, 0);
            }
        }
    }
    return 0;
}
