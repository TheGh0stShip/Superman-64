extern int D_8013B720;
extern int D_8013B724;
extern int D_8013B728;
extern unsigned char D_8013B730[];

void func_8000A9C0(int x, int y) {
    D_8013B730[(y - D_8013B724) * 31 + (x - D_8013B720) + 0x1E0] |= 4;
    D_8013B728++;
}
