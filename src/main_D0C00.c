typedef signed short s16;
typedef unsigned char u8;

typedef struct {
    u8 bytes[0x30];
} RuntimeRecord;

typedef struct {
    u8 pad00[0x14];
    u8 queue[0x28];
    int index;
    RuntimeRecord *records;
} RuntimeOwner;

typedef struct {
    s16 type;
    s16 pad2;
    RuntimeRecord *record;
    u8 value;
    u8 pad9[7];
} RuntimeMessage;

extern void func_800C0C6C(void *, RuntimeMessage *, int);

void func_800D0000(RuntimeOwner *owner, u8 value) {
    u8 storage[16];
    RuntimeMessage *message;
    RuntimeRecord *records;

    message = (RuntimeMessage *)storage;
    records = owner->records;
    message->type = 2;
    message->value = value;
    message->record = &records[owner->index];
    func_800C0C6C(owner->queue, message, 0);
}
