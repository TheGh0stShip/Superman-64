extern short D_8017A320;
extern short D_800E8B20[];
extern void *D_800D6104;

extern void func_800C45F0(void *arg0, int arg1);
extern void func_800C3CB0(void *arg0, unsigned char arg1);
extern int func_800D0210(void *arg0);
extern void func_800BFE40(void *arg0);

void func_80002A80(int index, unsigned char value) {
    if (D_8017A320 == 0) {
        if (D_800E8B20[index] != -1) {
            func_800C45F0(D_800D6104, D_800E8B20[index]);
            func_800C3CB0(D_800D6104, value);
        }
    }
}

void func_80002AF0(int index) {
    if (D_8017A320 == 0) {
        if (D_800E8B20[index] != -1) {
            func_800C45F0(D_800D6104, D_800E8B20[index]);
            if (func_800D0210(D_800D6104) == 1) {
                func_800BFE40(D_800D6104);
            }
        }
    }
}
