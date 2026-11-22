typedef unsigned char u8;
typedef signed int s32;

extern u8 D_800D6114[];

void func_800035F8(u8 *arg0, u8 *arg1) {
    s32 i;

    i = 0;
    if (arg1[0] != 0) {
        do {
            arg0[i] = D_800D6114[arg1[i]];
            i += 1;
        } while (arg1[i] != 0);
    }
    arg0[i] = 0;
}
