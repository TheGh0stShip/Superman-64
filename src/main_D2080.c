typedef signed short s16;
typedef unsigned char u8;

typedef struct {
    s16 type;
    u8 payload[14];
} RuntimeMessage;

typedef struct {
    u8 pad00[0x48];
    u8 queue[1];
} RuntimeOwner;

extern void func_800C0C6C(void *queue, RuntimeMessage *message, int flag);

void func_800D1480(RuntimeOwner *owner) {
    RuntimeMessage message;

    message.type = 15;
    func_800C0C6C(owner->queue, &message, 0);
}
