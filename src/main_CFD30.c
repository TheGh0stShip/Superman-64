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

#define CHECK_RESULT(call) \
    result = call;          \
    if (result != 0)        \
        return result

extern s32 func_800C7420(Pfs *pfs);
extern s32 func_800C783C(Pfs *pfs);
extern s32 func_800CAB50(Pfs *pfs, u16 company_code, u32 game_code,
                         u8 *game_name, u8 *ext_name, s32 *file_no);
extern s32 func_800D3040(MessageQueue *queue, s32 channel, u16 address,
                         u8 *buffer);
extern s32 func_800C751C(Pfs *pfs, Inode *inode, u8 flag, u8 bank);
extern s32 func_800D19A0(MessageQueue *queue, s32 channel, u16 address,
                         u8 *buffer, s32 force);
extern u16 func_800C6B50(u8 *data, s32 length);

s32 func_800CF410(Pfs *pfs, Inode *inode, u8 start_page, u16 *sum, u8 bank,
                  InodeUnit *last_page, s32 flag);
s32 func_800CF658(Pfs *pfs, u8 page_no, u16 *sum, u8 bank);

s32 func_800CF130(Pfs *pfs, u16 company_code, u32 game_code, u8 *game_name,
                  u8 *ext_name) {
    s32 file_no;
    s32 index;
    s32 result;
    Inode inode;
    Directory directory;
    u16 sum = 0;
    InodeUnit last_page;
    u8 start_page;
    u8 bank;

    if (company_code == 0 || game_code == 0) {
        return 5;
    }

    if (!(pfs->status & 1)) {
        return 5;
    }
    if (func_800C7420(pfs) == 2) {
        return 2;
    }
    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        CHECK_RESULT(func_800C783C(pfs));
    }
    CHECK_RESULT(func_800CAB50(pfs, company_code, game_code, game_name,
                               ext_name, &file_no));

    if (file_no == -1) {
        return 5;
    }
    CHECK_RESULT(func_800D3040(pfs->queue, pfs->channel,
                                pfs->dir_table + file_no,
                                (u8 *)&directory));

    start_page = directory.start_page.inode_t.page;

    for (bank = directory.start_page.inode_t.bank; bank < pfs->banks;) {
        CHECK_RESULT(func_800C751C(pfs, &inode, 0, bank));
        CHECK_RESULT(func_800CF410(pfs, &inode, start_page, &sum, bank,
                                   &last_page, 1));
        CHECK_RESULT(func_800C751C(pfs, &inode, 1, bank));

        if (last_page.ipage == 1) {
            break;
        }

        bank = last_page.inode_t.bank;
        start_page = last_page.inode_t.page;
    }

    if (bank >= pfs->banks) {
        return 3;
    }

    directory.game_code = 0;
    directory.company_code = 0;
    directory.start_page.ipage = 0;
    directory.data_sum = 0;
    for (index = 0; index < 16; index++) {
        directory.game_name[index] = 0;
    }
    for (index = 0; index < 4; index++) {
        directory.ext_name[index] = 0;
    }
    directory.status = 0;

    result = func_800D19A0(pfs->queue, pfs->channel,
                            pfs->dir_table + file_no,
                            (u8 *)&directory, 0);

    return result;
}

s32 func_800CF410(Pfs *pfs, Inode *inode, u8 start_page, u16 *sum, u8 bank,
                  InodeUnit *last_page, s32 flag) {
    InodeUnit next_page;
    InodeUnit old_page;
    s32 result;
    s32 offset;
    result = 0;
    next_page = inode->inode_page[start_page];

    if (next_page.ipage != 1) {
        offset = next_page.inode_t.bank > 0 ? 1 : pfs->inode_start_page;
    } else {
        offset = bank > 0 ? 1 : pfs->inode_start_page;
    }

    if (next_page.inode_t.page < offset && next_page.ipage != 1) {
        return 3;
    }

    *last_page = next_page;

    if (flag == 1) {
        inode->inode_page[start_page].ipage = 3;
    }

    CHECK_RESULT(func_800CF658(pfs, start_page, sum, bank));

    if (next_page.ipage == 1) {
        return 0;
    }

    while (next_page.ipage >= pfs->inode_start_page) {
        old_page = next_page;
        next_page = inode->inode_page[next_page.inode_t.page];
        inode->inode_page[old_page.inode_t.page].ipage = 3;

        CHECK_RESULT(func_800CF658(pfs, old_page.inode_t.page, sum, bank));

        if (next_page.inode_t.bank != bank) {
            break;
        }
    }

    if (next_page.ipage >= pfs->inode_start_page &&
        next_page.inode_t.bank == bank) {
        inode->inode_page[next_page.inode_t.page].ipage = 3;
    }

    *last_page = next_page;
    return 0;
}

s32 func_800CF658(Pfs *pfs, u8 page_no, u16 *sum, u8 bank) {
    s32 index;
    s32 result;
    u8 data[32];
    result = 0;
    pfs->activebank = bank;
    CHECK_RESULT(func_800C783C(pfs));
    for (index = 0; index < 8; index++) {
        result = func_800D3040(pfs->queue, pfs->channel,
                                page_no * 8 + index, data);
        if (result != 0) {
            pfs->activebank = 0;
            func_800C783C(pfs);
            return result;
        }
        *sum = *sum + func_800C6B50(data, sizeof(data));
    }
    pfs->activebank = 0;
    result = func_800C783C(pfs);
    return result;
}
