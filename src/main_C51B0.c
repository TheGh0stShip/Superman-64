typedef signed short s16;
typedef unsigned char u8;

typedef struct {
    s16 type;
    s16 pad2;
    void *data;
    int pad8;
    int padC;
} PointerMessage;

typedef struct {
    u8 value;
} EventQueue;

typedef struct {
    u8 pad[0x48];
    EventQueue queue;
} EventOwner;

extern void func_800C0C6C(EventQueue *, PointerMessage *, int);

void func_800C45B0(EventOwner *arg0, void *arg1) {
    PointerMessage message;

    message.type = 13;
    message.data = arg1;
    func_800C0C6C(&arg0->queue, &message, 0);
}
