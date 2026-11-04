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

extern u8 D_80145421;
extern PackedEntry D_801453E0[];
extern int D_8014541C;

void func_800BFB30(u8 value) {
    PackedEntry *entry;
    PackedEntry initial;
    int index;

    for (index = 0; index < 15; index++) {
        ((int *)D_801453E0)[index] = 0;
    }

    D_8014541C = 1;
    entry = D_801453E0;
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
