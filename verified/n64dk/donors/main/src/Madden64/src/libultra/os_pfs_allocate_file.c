#include "pfs.h"

s32 osPfsAllocateFile(OSPfs* pfs, u16 companyCode, u32 gameCode,
                      u8* gameName, u8* extName, int byteCount,
                      s32* fileNo) {
    int startPage;
    int allocated;
    int lastPage;
    int oldLastPage = 0;
    int index;
    s32 result = 0;
    int pageCount;
    OSInode inode;
    OSInode backupInode;
    OSDir directory;
    u8 bank;
    u8 oldBank = 0;
    int firstTime = 0;
    s32 freeBytes;
    OSInodeUnit firstPage;

    if (companyCode == 0 || gameCode == 0) {
        return 5;
    }
    pageCount = (byteCount + 255) / 256;
    if ((pfs->status & 1) == 0) {
        return 5;
    }
    if (__osCheckId(pfs) == 2) {
        return 2;
    }
    result = osPfsFindFile(pfs, companyCode, gameCode, gameName, extName, fileNo);
    if (result != 0 && result != 5) {
        return result;
    }
    if (*fileNo != -1) {
        return 9;
    }
    result = osPfsFreeBlocks(pfs, &freeBytes);
    if (byteCount > freeBytes) {
        return 7;
    }
    if (pageCount != 0) {
        result = osPfsFindFile(pfs, 0, 0, (u8*)0, (u8*)0, fileNo);
        if (result != 0 && result != 5) {
            return result;
        }
        if (*fileNo == -1) {
            return 8;
        }
        for (bank = 0; bank < pfs->banks; bank++) {
            result = __osPfsRWInode(pfs, &inode, 0, bank);
            if (result != 0) {
                return result;
            }
            result = __osPfsDeclearPage(pfs, &inode, pageCount, &startPage,
                                        bank, &allocated, &lastPage);
            if (result != 0) {
                return result;
            }
            if (startPage != -1) {
                if (firstTime == 0) {
                    firstPage.inode.page = startPage;
                    firstPage.inode.bank = bank;
                } else {
                    backupInode.inode_page[oldLastPage].inode.bank = bank;
                    backupInode.inode_page[oldLastPage].inode.page = startPage;
                    result = __osPfsRWInode(pfs, &backupInode, 1, oldBank);
                    if (result != 0) {
                        return result;
                    }
                }
                for (index = 0; index < 128; index++) {
                    backupInode.inode_page[index].ipage = inode.inode_page[index].ipage;
                }
                oldLastPage = lastPage;
                oldBank = bank;
                firstTime++;
                if (pageCount > allocated) {
                    pageCount = pageCount - allocated;
                } else {
                    pageCount = 0;
                    break;
                }
            }
        }
        if (pageCount > 0 || startPage == -1) {
            return 3;
        }
        backupInode.inode_page[oldLastPage].inode.bank = bank;
        backupInode.inode_page[oldLastPage].inode.page = startPage;
        result = __osPfsRWInode(pfs, &backupInode, 1, oldBank);
        if (result != 0) {
            return result;
        }
        directory.start_page = firstPage;
        directory.company_code = companyCode;
        directory.game_code = gameCode;
        directory.data_sum = 0;
        for (index = 0; index < 16; index++) {
            directory.game_name[index] = *gameName++;
        }
        for (index = 0; index < 4; index++) {
            directory.ext_name[index] = *extName++;
        }
        result = __osContRamWrite(pfs->queue, pfs->channel,
                                  pfs->dir_table + *fileNo,
                                  (u8*)&directory, 0);
        if (result != 0) {
            return result;
        }
        return result;
    }
    return 5;
}
