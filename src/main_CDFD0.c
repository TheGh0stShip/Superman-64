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
    s16 value;
    u8 padA[6];
} RuntimeMessage;

extern void func_800C0C6C(void *, RuntimeMessage *, int);

void func_800CD3D0(RuntimeOwner *owner, s16 value) {
    u8 storage[16];
    RuntimeMessage *message;
    RuntimeRecord *records;

    message = (RuntimeMessage *)storage;
    records = owner->records;
    message->type = 3;
    message->record = &records[owner->index];
    message->value = value;
    func_800C0C6C(owner->queue, message, 0);
}
