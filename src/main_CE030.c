typedef signed short s16;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    s16 type;
    s16 pad2;
    u32 arg1;
    u32 arg2;
    u32 arg3;
} ThreeValueMessage;

typedef struct {
    u8 value;
} EventQueue;

typedef struct {
    u8 pad[0x48];
    EventQueue queue;
} EventOwner;

extern void func_800C0C6C(EventQueue *, ThreeValueMessage *, int);

void func_800CD430(EventOwner *arg0, u32 arg1, u32 arg2, u32 arg3) {
    ThreeValueMessage message;

    message.type = 11;
    message.arg1 = arg1;
    message.arg2 = arg2;
    message.arg3 = arg3;
    func_800C0C6C(&arg0->queue, &message, 0);
}
