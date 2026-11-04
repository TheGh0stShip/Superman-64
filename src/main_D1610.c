typedef signed char s8;
typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;

typedef struct MessageQueue MessageQueue;

typedef union {
    struct {
        u8 bank;
        u8 page;
    } inode_t;
    u16 ipage;
} InodeUnit;

typedef struct {
    u32 game_code;
    u16 company_code;
    InodeUnit start_page;
    u8 status;
    s8 reserved;
    u16 data_sum;
    u8 ext_name[4];
    u8 game_name[16];
} Directory;

typedef struct {
    InodeUnit inode_page[128];
} Inode;

typedef struct {
    Inode inode;
    u8 bank;
    u8 map[256];
} InodeCache;

typedef struct {
    s32 status;
    MessageQueue *queue;
    s32 channel;
    u8 id[32];
    u8 label[32];
    s32 version;
    s32 dir_size;
    s32 inode_table;
    s32 minode_table;
    s32 dir_table;
    s32 inode_start_page;
    u8 banks;
    u8 activebank;
} Pfs;

#define CHECK_PAGE(p)                                                        \
    ((p).ipage >= pfs->inode_start_page &&                                  \
     (p).inode_t.bank < pfs->banks && (p).inode_t.page >= 1 &&               \
     (p).inode_t.page < 0x80)

#define CHECK_RESULT(call) \
    result = call;          \
    if (result != 0)        \
        return result

extern s32 func_800C7420(Pfs *pfs);
extern s32 func_800C71C4(Pfs *pfs);
extern s32 func_800D3040(MessageQueue *queue, s32 channel, u16 address,
                         u8 *buffer);
extern s32 func_800D19A0(MessageQueue *queue, s32 channel, u16 address,
                         u8 *buffer, s32 force);
extern s32 func_800C751C(Pfs *pfs, Inode *inode, u8 flag, u8 bank);
extern s32 func_800C783C(Pfs *pfs);

s32 func_800D10D4(Pfs *pfs, InodeCache *cache);
s32 func_800D1288(Pfs *pfs, InodeUnit first_page, InodeCache *cache);

s32 func_800D0A10(Pfs *pfs) {
    s32 index;
    s32 result;
    InodeUnit next_page;
    Inode checked_inode;
    Inode temporary_inode;
    Directory directory;
    InodeUnit file_next_node[16];
    InodeCache cache;
    s32 fixed = 0;
    u8 bank;
    s32 current_count;
    s32 last_count;
    s32 offset;

    result = func_800C7420(pfs);

    if (result == 2) {
        result = func_800C71C4(pfs);
    }

    if (result != 0) {
        return result;
    }

    CHECK_RESULT(func_800D10D4(pfs, &cache));

    for (index = 0; index < pfs->dir_size; index++) {
        CHECK_RESULT(func_800D3040(pfs->queue, pfs->channel,
                                   pfs->dir_table + index, (u8 *)&directory));

        if (directory.company_code != 0 && directory.game_code != 0) {
            next_page = directory.start_page;
            last_count = current_count = 0;
            bank = 255;

            while (CHECK_PAGE(next_page)) {
                if (bank != next_page.inode_t.bank) {
                    bank = next_page.inode_t.bank;
                    result = func_800C751C(pfs, &temporary_inode, 0, bank);
                    if (result != 0 && result != 3) {
                        return result;
                    }
                }

                if ((current_count =
                         func_800D1288(pfs, next_page, &cache) - last_count) !=
                    0) {
                    break;
                }

                last_count = 1;
                next_page = temporary_inode.inode_page[next_page.inode_t.page];
            }

            if (current_count != 0 || next_page.ipage != 1) {
                directory.company_code = 0;
                directory.game_code = 0;
                directory.start_page.ipage = 0;
                directory.status = 0;
                directory.data_sum = 0;

                if (pfs->activebank != 0) {
                    pfs->activebank = 0;
                    CHECK_RESULT(func_800C783C(pfs));
                }
                CHECK_RESULT(func_800D19A0(pfs->queue, pfs->channel,
                                           pfs->dir_table + index,
                                           (u8 *)&directory, 0));
                fixed++;
            }
        } else {
            if (directory.company_code != 0 || directory.game_code != 0) {
                directory.company_code = 0;
                directory.game_code = 0;
                directory.start_page.ipage = 0;
                directory.status = 0;
                directory.data_sum = 0;

                if (pfs->activebank != 0) {
                    pfs->activebank = 0;
                    CHECK_RESULT(func_800C783C(pfs));
                }
                CHECK_RESULT(func_800D19A0(pfs->queue, pfs->channel,
                                           pfs->dir_table + index,
                                           (u8 *)&directory, 0));
                fixed++;
            }
        }
    }
    for (index = 0; index < pfs->dir_size; index++) {
        CHECK_RESULT(func_800D3040(pfs->queue, pfs->channel,
                                   pfs->dir_table + index, (u8 *)&directory));

        if (directory.company_code != 0 && directory.game_code != 0 &&
            directory.start_page.ipage >= (u16)pfs->inode_start_page) {
            file_next_node[index].ipage = directory.start_page.ipage;
        } else {
            file_next_node[index].ipage = 0;
        }
    }

    for (bank = 0; bank < pfs->banks; bank++) {
        result = func_800C751C(pfs, &temporary_inode, 0, bank);

        if (result != 0 && result != 3) {
            return result;
        }

        offset = bank > 0 ? 1 : pfs->inode_start_page;

        for (index = 0; index < offset; index++) {
            checked_inode.inode_page[index].ipage =
                temporary_inode.inode_page[index].ipage;
        }

        for (; index < 128; index++) {
            checked_inode.inode_page[index].ipage = 3;
        }

        for (index = 0; index < pfs->dir_size; index++) {
            while (file_next_node[index].inode_t.bank == bank &&
                   file_next_node[index].ipage >=
                       (u16)pfs->inode_start_page) {
                u8 page = file_next_node[index].inode_t.page;
                file_next_node[index] = checked_inode.inode_page[page] =
                    temporary_inode.inode_page[page];
            }
        }
        CHECK_RESULT(func_800C751C(pfs, &checked_inode, 1, bank));
    }

    if (fixed) {
        pfs->status |= 2;
    } else {
        pfs->status &= ~2;
    }

    return 0;
}

s32 func_800D10D4(Pfs *pfs, InodeCache *cache) {
    s32 index;
    s32 map_index;
    s32 offset;
    u8 bank;
    InodeUnit page;
    Inode temporary_inode;
    s32 result;

    for (index = 0; index < 256; index++) {
        cache->map[index] = 0;
    }

    cache->bank = -1;
    for (bank = 0; bank < pfs->banks; bank++) {
        offset = bank > 0 ? 1 : pfs->inode_start_page;

        result = func_800C751C(pfs, &temporary_inode, 0, bank);

        if (result != 0 && result != 3) {
            return result;
        }

        for (index = offset; index < 128; index++) {
            page = temporary_inode.inode_page[index];

            if (page.ipage >= pfs->inode_start_page &&
                page.inode_t.bank != bank) {
                map_index = page.inode_t.page / 4 +
                            (page.inode_t.bank % 8) * 32;
                cache->map[map_index] |= 1 << (bank % 8);
            }
        }
    }
    return 0;
}

s32 func_800D1288(Pfs *pfs, InodeUnit first_page, InodeCache *cache) {
    s32 index;
    s32 map_index;
    s32 hits;
    u8 bank;
    s32 offset;
    s32 result;

    hits = 0;
    result = 0;
    map_index = first_page.inode_t.page / 4 +
                (first_page.inode_t.bank % 8) * 32;

    for (bank = 0; bank < pfs->banks; bank++) {
        offset = bank > 0 ? 1 : pfs->inode_start_page;

        if (bank == first_page.inode_t.bank ||
            cache->map[map_index] & (1 << (bank % 8))) {
            if (bank != cache->bank) {
                result = func_800C751C(pfs, &cache->inode, 0, bank);

                if (result != 0 && result != 3) {
                    return result;
                }

                cache->bank = bank;
            }

            for (index = offset;
                 hits < 2 && index < 128; index++) {
                if (cache->inode.inode_page[index].ipage == first_page.ipage) {
                    hits++;
                }
            }

            if (hits >= 2) {
                return 2;
            }
        }
    }
    return hits;
}
