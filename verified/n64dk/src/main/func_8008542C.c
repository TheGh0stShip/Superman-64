typedef signed int s32;
typedef unsigned short u16;

extern u16 *D_80142B8C;
extern s32 D_80142C30;
extern s32 D_80142C34;

u16 func_8008542C(s32 arg0, s32 arg1, s32 arg2) {
    u16 sp6;

    sp6 = D_80142B8C[(arg2 * D_80142C30) + arg0 +
                     ((arg1 * D_80142C30) * D_80142C34)];
    return sp6;
}
