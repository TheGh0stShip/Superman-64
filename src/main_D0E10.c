typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad00[0x28];
    int value;
    u8 pad2C[4];
} RuntimeRecord;

typedef struct {
    u8 pad00[0x3C];
    int index;
    RuntimeRecord *records;
} RuntimeOwner;

int func_800D0210(RuntimeOwner *owner) {
    RuntimeRecord *records = owner->records;

    return *(int *)(owner->index * 0x30 + (u32)records + 0x28);
}
