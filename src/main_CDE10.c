typedef signed short s16;
typedef unsigned char u8;

typedef struct {
    s16 type;
    s16 pad2;
    s16 value;
    s16 pad6;
    int pad8;
    int padC;
} ValueMessage;

typedef struct {
    u8 value;
} EventQueue;

typedef struct {
    u8 pad[0x48];
    EventQueue queue;
} EventOwner;

extern void func_800C0C6C(EventQueue *, ValueMessage *, int);

void func_800CD210(register EventOwner *arg0, s16 arg1) {
    ValueMessage message;

    message.type = 10;
    message.value = arg1;
    func_800C0C6C(&arg0->queue, &message, 0);
}
