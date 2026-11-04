typedef unsigned char u8;
typedef unsigned short u16;

typedef struct MessageQueue MessageQueue;

typedef struct {
    u8 pad0[0x18];
    u16 device_id;
    u8 banks;
    u8 version;
    u16 checksum;
    u16 inverted_checksum;
} PackId;

typedef struct {
    int status;
    MessageQueue *queue;
    int channel;
    u8 id[32];
    u8 label[32];
    int version;
    int directory_size;
    int inode_table;
    int mirror_inode_table;
    int directory_table;
    int inode_start_page;
    u8 banks;
    u8 active_bank;
} Pfs;

extern int func_800C783C(Pfs *pfs);
extern int func_800D3040(MessageQueue *queue, int channel, int address,
                         u8 *buffer);
extern void func_800C6BAC(u16 *data, u16 *sum, u16 *inverted_sum);
extern int func_800C702C(Pfs *pfs, PackId *id);
extern int func_800C6C14(Pfs *pfs, PackId *id, PackId *new_id);

int func_800CD870(Pfs *pfs) {
    int index;
    u16 sum;
    u16 inverted_sum;
    u8 temporary[32];
    PackId new_id;
    int result;
    PackId *id;

    if (pfs->active_bank != 0) {
        pfs->active_bank = 0;
        result = func_800C783C(pfs);
        if (result != 0) {
            return result;
        }
    }

    result = func_800D3040(pfs->queue, pfs->channel, 1, temporary);
    if (result != 0) {
        return result;
    }

    func_800C6BAC((u16 *)temporary, &sum, &inverted_sum);
    id = (PackId *)temporary;

    if (id->checksum != sum || id->inverted_checksum != inverted_sum) {
        result = func_800C702C(pfs, id);
        if (result == 10) {
            result = func_800C6C14(pfs, id, &new_id);
            if (result != 0) {
                return result;
            }
            id = &new_id;
        } else if (result != 0) {
            return result;
        }
    }

    if ((id->device_id & 1) == 0) {
        result = func_800C6C14(pfs, id, &new_id);
        if (result != 0) {
            return result;
        }
        id = &new_id;
        if ((id->device_id & 1) == 0) {
            return 11;
        }
    }

    for (index = 0; index < 32; index++) {
        pfs->id[index] = ((u8 *)id)[index];
    }
    pfs->version = id->version;
    pfs->banks = id->banks;
    pfs->inode_start_page = 3 + (2 * pfs->banks);
    pfs->directory_size = 16;
    pfs->inode_table = 8;
    pfs->mirror_inode_table = (1 + pfs->banks) * 8;
    pfs->directory_table = pfs->mirror_inode_table + pfs->banks * 8;

    result = func_800D3040(pfs->queue, pfs->channel, 7, pfs->label);
    if (result != 0) {
        return result;
    }
    return 0;
}
