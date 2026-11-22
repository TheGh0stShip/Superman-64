typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;

typedef struct Entry {
    u8 pad[7];
    s8 value7;
} Entry;

extern u16 *D_80142B8C;
extern Entry *D_80142B98;
extern s32 D_80142C30;
extern s32 D_80142C34;

s8 func_800853B4(s32 arg0, s32 arg1, s32 arg2) {
    u16 index;

    index = D_80142B8C[arg2 * D_80142C30 + arg0
        + arg1 * D_80142C30 * D_80142C34];
    return D_80142B98[index].value7;
}
