typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;

extern s16 D_8017A320;
extern s16 D_800E8B20[];
extern void *D_800D6104;

extern void func_800C45F0(void *, s16);
extern s32 alSndpGetState(void *);
extern void alSndpStop(void *);
extern void func_800028C4(s32, s32, s16, u8, u8, s32);

void func_8000277C(s32 arg0, s32 arg1, s16 arg2, u8 arg3, u8 arg4) {
    s32 counter;

    if ((D_8017A320 == 0) && (D_800E8B20[arg0] != -1)) {
        func_800C45F0(D_800D6104, D_800E8B20[arg0]);
        if (arg0 == 0) {
            if (alSndpGetState(D_800D6104) == 1) {
                return;
            }
        } else {
            alSndpStop(D_800D6104);
            counter = 0;
            if ((alSndpGetState(D_800D6104) == 1) && (counter < 0xFA00)) {
                do {
                    counter++;
                } while ((alSndpGetState(D_800D6104) == 1) &&
                         (counter < 0xFA00));
            }
        }
        if (arg2 >= 0x8000) {
            arg2 = 0x7FFF;
        }
        func_800028C4(arg0, arg1, arg2, arg3, arg4, 0x1388);
    }
}
