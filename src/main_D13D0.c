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
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 typeh;
    u8 typel;
    u8 status;
} RequestFormat;

typedef struct {
    u16 type;
    u8 status;
    u8 error;
} ControllerStatus;

extern u8 D_80145420;
extern PifRam D_80145890;

extern s32 func_800C3C00(s32 direction, void *address);
extern s32 func_800BE170(MessageQueue *queue, void *message, s32 flag);

void func_800D08B4(s32 channel);
void func_800D0974(s32 channel, ControllerStatus *data);

s32 func_800D07D0(MessageQueue *queue, s32 channel) {
    s32 result = 0;
    void *message;
    ControllerStatus data;

    func_800D08B4(channel);

    result = func_800C3C00(1, &D_80145890);
    func_800BE170(queue, &message, 1);

    result = func_800C3C00(0, &D_80145890);
    func_800BE170(queue, &message, 1);

    func_800D0974(channel, &data);

    if ((data.status & 1) != 0 && (data.status & 2) != 0) {
        return 2;
    } else if (data.error != 0 || (data.status & 1) == 0) {
        return 1;
    } else if ((data.status & 4) != 0) {
        return 4;
    }

    return result;
}

void func_800D08B4(s32 channel) {
    u8 *pointer;
    RequestFormat request;
    s32 index;

    D_80145420 = 0;
    D_80145890.status = 1;

    pointer = (u8 *)&D_80145890;

    request.txsize = 1;
    request.rxsize = 3;
    request.cmd = 0;
    request.typeh = 0xFF;
    request.typel = 0xFF;
    request.status = 0xFF;

    for (index = 0; index < channel; index++) {
        *pointer++ = 0;
    }

    *(RequestFormat *)pointer = request;
    pointer += sizeof(RequestFormat);
    *pointer = 0xFE;
}

void func_800D0974(s32 channel, ControllerStatus *data) {
    u8 *pointer = (u8 *)&D_80145890;
    RequestFormat request;
    s32 index;

    for (index = 0; index < channel; index++) {
        pointer++;
    }

    request = *(RequestFormat *)pointer;
    data->error = (request.rxsize & 0xC0) >> 4;

    if (data->error != 0) {
        return;
    }

    data->type = (request.typel << 8) | request.typeh;
    data->status = request.status;
}
