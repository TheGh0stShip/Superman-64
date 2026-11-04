typedef unsigned char u8;
typedef signed int s32;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct MessageQueue MessageQueue;

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

typedef struct {
    u32 repaired;
    u32 random;
    u64 serial_mid;
    u64 serial_low;
    u16 deviceid;
    u8 banks;
    u8 version;
    u16 checksum;
    u16 inverted_checksum;
} PackId;

#define CHECK_RESULT(call) \
    result = call;          \
    if (result != 0)        \
        return result

extern void func_800BFC80(void);
extern void func_800BFCC4(void);
extern s32 func_800D07D0(MessageQueue *queue, s32 channel);
extern s32 func_800C783C(Pfs *pfs);
extern s32 func_800D3040(MessageQueue *queue, s32 channel, u16 address,
                         u8 *buffer);
extern s32 func_800C6BAC(u16 *data, u16 *checksum, u16 *inverse);
extern s32 func_800C702C(Pfs *pfs, PackId *id);
extern s32 func_800C6C14(Pfs *pfs, PackId *old_id, PackId *new_id);
extern s32 func_800D0A10(Pfs *pfs);

s32 func_800D0530(MessageQueue *queue, Pfs *pfs, s32 channel) {
    s32 index;
    s32 result = 0;
    u16 checksum;
    u16 inverse;
    u8 temporary[32];
    PackId *id;
    PackId new_id;

    func_800BFC80();

    result = func_800D07D0(queue, channel);

    func_800BFCC4();

    if (result != 0) {
        return result;
    }

    pfs->queue = queue;
    pfs->channel = channel;
    pfs->status = 0;

    pfs->activebank = 0;
    CHECK_RESULT(func_800C783C(pfs));
    CHECK_RESULT(func_800D3040(pfs->queue, pfs->channel, 1, temporary));

    func_800C6BAC((u16 *)temporary, &checksum, &inverse);
    id = (PackId *)temporary;

    if (id->checksum != checksum || id->inverted_checksum != inverse) {
        result = func_800C702C(pfs, id);

        if (result != 0) {
            return result;
        } else if (result != 0) {
            return result;
        }
    }

    if (!(id->deviceid & 1)) {
        result = func_800C6C14(pfs, id, &new_id);

        if (result != 0) {
            return result;
        }

        id = &new_id;

        if (!(id->deviceid & 1)) {
            return 11;
        }
    }

    for (index = 0; index < 32; index++) {
        pfs->id[index] = ((u8 *)id)[index];
    }

    pfs->version = id->version;
    pfs->banks = id->banks;
    pfs->inode_start_page = 1 + 2 + 2 * pfs->banks;
    pfs->dir_size = 2 * 8;
    pfs->inode_table = 1 * 8;
    pfs->minode_table = (1 + pfs->banks) * 8;
    pfs->dir_table = pfs->minode_table + pfs->banks * 8;

    CHECK_RESULT(func_800D3040(pfs->queue, pfs->channel, 7, pfs->label));

    result = func_800D0A10(pfs);
    pfs->status |= 1;

    return result;
}
