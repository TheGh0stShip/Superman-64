typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;

typedef struct Entry {
    u8 pad00[0x10];
    u16 value10;
    u16 value12;
    u8 pad14[4];
    s32 value18;
    s32 value1C;
    u8 pad20[4];
    u16 value24;
} Entry;

extern Entry *D_800D7FE0[];
extern s32 D_80142B68;
extern Entry *D_80142B80;
extern s32 D_80142B8C;
extern s32 D_80142B98;
extern s32 D_80142BE0;
extern s32 D_80142C30;
extern s32 D_80142C34;

void func_80085350(void) {
    D_80142B80 = D_800D7FE0[D_80142B68];
    D_80142BE0 = D_80142B80->value24;
    D_80142B8C = D_80142B80->value18;
    D_80142B98 = D_80142B80->value1C;
    D_80142C30 = D_80142B80->value10;
    D_80142C34 = D_80142B80->value12;
}
