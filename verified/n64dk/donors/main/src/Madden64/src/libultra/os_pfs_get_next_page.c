#include "pfs.h"

#define PAGE_VALID(pfs, node)                                      \
    ((node).ipage >= (pfs)->inode_start_page &&                    \
     (node).inode.bank < (pfs)->banks && (node).inode.page > 0 &&  \
     (node).inode.page < 128)

s32 __osPfsGetNextPage(OSPfs* pfs, u8* bank, OSInode* inode,
                       OSInodeUnit* page) {
    s32 result;

    if (page->inode.bank != *bank) {
        *bank = page->inode.bank;
        result = __osPfsRWInode(pfs, inode, 0, *bank);
        if (result != 0) {
            return result;
        }
    }
    *page = inode->inode_page[page->inode.page];
    if (!PAGE_VALID(pfs, *page)) {
        if (page->ipage == 1) {
            return 5;
        }
        return 3;
    }
    return 0;
}
