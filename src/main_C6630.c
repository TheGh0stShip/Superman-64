typedef unsigned char u8;

typedef struct {
    u8 byte0;
    u8 byte1;
    u8 byte2;
    u8 byte3;
    u8 byte4;
    u8 byte5;
    u8 byte6;
    u8 byte7;
} PackedEntry;

extern u8 D_80145420;
extern u8 D_80145421;
extern PackedEntry D_80145890[];
extern int D_801458CC;

void func_800C5A30(u8 value) {
    PackedEntry *entry;
    PackedEntry initial;
    int index;

    entry = D_80145890;
    D_80145420 = value;
    D_801458CC = 1;
    initial.byte0 = 0xFF;
    initial.byte1 = 1;
    initial.byte2 = 3;
    initial.byte3 = value;
    initial.byte4 = 0xFF;
    initial.byte5 = 0xFF;
    initial.byte6 = 0xFF;
    initial.byte7 = 0xFF;
    index = 0;

    for (; index < D_80145421; index++) {
        *entry = initial;
        entry++;
    }
    entry->byte0 = 0xFE;
}
