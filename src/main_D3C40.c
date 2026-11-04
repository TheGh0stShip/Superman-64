typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u32 validCount;
    u32 first;
    s32 msgCount;
    void *msg;
    void *mtqueue;
    void *fullqueue;
} MessageQueue;

typedef struct {
    u32 ramarray[15];
    u32 status;
} PifRam;

typedef struct {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u16 address;
    u8 data[32];
    u8 datacrc;
} RamReadFormat;

extern u8 D_80145420;
extern PifRam D_80145890;
extern s32 D_801458CC;

extern void func_800BFC80(void);
extern void func_800BFCC4(void);
extern s32 func_800C3C00(s32 direction, void *address);
extern s32 func_800BE170(MessageQueue *queue, void *message, s32 flag);
extern u8 func_800CEB20(u16 address);
extern u8 func_800CEBD0(u8 *data);
extern s32 func_800D07D0(MessageQueue *queue, s32 channel);

static void func_800D325C(s32 channel, u16 address);

s32 func_800D3040(MessageQueue *queue, s32 channel, u16 address, u8 *buffer) {
    s32 result = 0;
    s32 index;
    u8 *pointer = (u8 *)&D_80145890;
    RamReadFormat format;
    s32 retry = 2;

    func_800BFC80();
    D_80145420 = 2;
    func_800D325C(channel, address);
    result = func_800C3C00(1, &D_80145890);
    func_800BE170(queue, 0, 1);

    do {
        result = func_800C3C00(0, &D_80145890);
        func_800BE170(queue, 0, 1);
        pointer = (u8 *)&D_80145890;

        if (channel != 0) {
            for (index = 0; index < channel; index++) {
                pointer++;
            }
        }

        format = *(RamReadFormat *)pointer;
        result = (format.rxsize & 0xC0) >> 4;
        if (result == 0) {
            u8 crc = func_800CEBD0((u8 *)&format.data);
            if (crc != format.datacrc) {
                result = func_800D07D0(queue, channel);

                if (result != 0) {
                    func_800BFCC4();
                    return result;
                }

                result = 4;
            } else {
                for (index = 0; index < 32; index++) {
                    *buffer++ = format.data[index];
                }
            }
        } else {
            result = 1;
        }
    } while (result == 4 && retry-- >= 0);

    func_800BFCC4();
    return result;
}

static void func_800D325C(s32 channel, u16 address) {
    u8 *pointer;
    RamReadFormat format;
    s32 index;

    pointer = (u8 *)D_80145890.ramarray;
    D_80145890.status = 1;
    format.dummy = 0xFF;
    format.txsize = 3;
    format.rxsize = 0x21;
    format.cmd = 2;
    format.address = (address << 5) | func_800CEB20(address);
    format.datacrc = 0xFF;

    for (index = 0; index < 32; index++) {
        format.data[index] = 0xFF;
    }

    if (channel != 0) {
        for (index = 0; index < channel; index++) {
            *pointer++ = 0;
        }
    }

    *(RamReadFormat *)pointer = format;
    pointer += sizeof(RamReadFormat);
    pointer[0] = 0xFE;
}
