typedef signed short s16;
typedef unsigned char u8;

typedef struct {
    s16 type;
    u8 priority;
    u8 status;
    void *address;
    float value;
    u8 payload[4];
} RuntimeMessage;

typedef struct {
    u8 pad00[0x14];
    u8 queue[0x28];
    int index;
    u8 *base;
} RuntimeOwner;

extern void func_800C0C6C(void *queue, RuntimeMessage *message, int flag);

void func_800C78C0(RuntimeOwner *owner, float value) {
    RuntimeMessage message;
    u8 *base = owner->base;

    message.type = 4;
    message.address = base + owner->index * 0x30;
    message.value = value;
    func_800C0C6C(owner->queue, &message, 0);
}
