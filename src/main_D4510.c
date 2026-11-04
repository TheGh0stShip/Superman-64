typedef signed short s16;
typedef unsigned char u8;

typedef struct {
    u8 pad0[0xD];
    u8 level;
} Object;

typedef struct {
    u8 pad0[0x1C];
    Object *object;
    s16 type;
    s16 pad22;
    float scale;
    int value28;
    s16 level;
    u8 flags;
    u8 pad2F;
} Slot;

typedef struct {
    u8 pad0[0x40];
    Slot *slots;
    int count;
} SlotPool;

s16 func_800D3910(SlotPool *pool, Object *object) {
    register Slot *slots = pool->slots;
    register s16 index = 0;
    register int count = pool->count;

    while (index < count) {
        Slot *slot = (Slot *)((u8 *)slots + index * 0x30);

        if (slot->object == 0) {
            slot->object = object;
            slot->type = 5;
            slot->value28 = 0;
            slot->flags = 0x40;
            slot->pad2F = 0;
            slot->scale = 1.0f;
            slot->level = object->level * 0x7FFF / 0x7F;
            return index;
        }
        index++;
    }
    return -1;
}
