typedef signed short s16;
typedef unsigned char u8;

typedef struct {
    s16 type;
    u8 priority;
    u8 status;
    void *address;
    u8 payload[8];
} RuntimeMessage;

typedef struct {
    u8 pad00[0x14];
    u8 queue[0x28];
    int index;
    u8 *base;
} RuntimeOwner;

extern void func_800C0C6C(void *queue, RuntimeMessage *message, int flag);

void func_800C3DD0(RuntimeOwner *owner, int flag) {
    RuntimeMessage message;
    u8 *base = owner->base;

    message.type = 0;
    message.address = base + owner->index * 0x30;
    func_800C0C6C(owner->queue, &message, flag);
}
