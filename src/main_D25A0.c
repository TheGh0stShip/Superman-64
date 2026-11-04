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
} RamWriteFormat;

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

static void func_800D1BA4(s32 channel, u16 address, u8 *buffer);

s32 func_800D19A0(MessageQueue *queue, s32 channel, u16 address, u8 *buffer,
                  s32 force) {
    s32 result = 0;
    s32 index;
    u8 *pointer = (u8 *)&D_80145890;
    RamWriteFormat format;
    s32 retry = 2;

    if (force != 1 && address < 7 && address != 0) {
        return 0;
    }

    func_800BFC80();
    D_80145420 = 3;
    func_800D1BA4(channel, address, buffer);
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

        format = *(RamWriteFormat *)pointer;
        result = (format.rxsize & 0xC0) >> 4;
        if (result == 0) {
            if (func_800CEBD0(buffer) != format.datacrc) {
                result = func_800D07D0(queue, channel);
                if (result != 0) {
                    func_800BFCC4();
                    return result;
                }
                result = 4;
            }
        } else {
            result = 1;
        }
    } while (result == 4 && retry-- >= 0);

    func_800BFCC4();
    return result;
}

static void func_800D1BA4(s32 channel, u16 address, u8 *buffer) {
    u8 *pointer;
    RamWriteFormat format;
    s32 index;

    pointer = (u8 *)D_80145890.ramarray;
    D_80145890.status = 1;
    format.dummy = 0xFF;
    format.txsize = 0x23;
    format.rxsize = 1;
    format.cmd = 3;
    format.address = (address << 5) | func_800CEB20(address);
    format.datacrc = 0xFF;

    for (index = 0; index < 32; index++) {
        format.data[index] = *buffer++;
    }
    if (channel != 0) {
        for (index = 0; index < channel; index++) { *pointer++ = 0; }
    }
    *(RamWriteFormat *)pointer = format;
    pointer += sizeof(RamWriteFormat);
    pointer[0] = 0xFE;
}
