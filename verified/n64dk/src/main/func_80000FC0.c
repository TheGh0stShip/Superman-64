typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

s32 osInvalDCache();
s32 osPiStartDma();
s32 osRecvMesg();
extern s16 D_800D60D0;
extern s32 D_800E85C0;
extern s32 D_800E85DC;

typedef struct OSIoMesg { u8 bytes[0x18]; } OSIoMesg;

void func_80000FC0(s32 arg0, s32 arg1, u32 arg2) {
    OSIoMesg sp30;
    u32 sp2C;
    if ((arg2 < 0xF000U) || (D_800D60D0 == 0)) {
        osInvalDCache(arg1, arg2);
        osPiStartDma(&sp30, 0, 0, arg0, arg1, arg2, &D_800E85C0);
        osRecvMesg(&D_800E85C0, &D_800E85DC, 1);
        return;
    }
    sp2C = (arg2 / 5U) & ~7;
    if (arg2 >= sp2C) {
        do {
            osInvalDCache(arg1, sp2C);
            osPiStartDma(&sp30, 0, 0, arg0, arg1, sp2C, &D_800E85C0);
            osRecvMesg(&D_800E85C0, &D_800E85DC, 1);
            arg0 += sp2C;
            arg1 += sp2C;
            arg2 -= sp2C;
            D_800D60D0 = 2;
loop_5:
            if (D_800D60D0 == 2) goto loop_5;
        } while (arg2 >= sp2C);
    }
    if (arg2 != 0) {
        osInvalDCache(arg1, arg2);
        osPiStartDma(&sp30, 0, 0, arg0, arg1, arg2, &D_800E85C0);
        osRecvMesg(&D_800E85C0, &D_800E85DC, 1);
    }
}
