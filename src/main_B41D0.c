extern short D_8014427E;
extern short D_80144278;
extern short D_8014427A;
extern int D_80144290;
extern int D_80144280;
extern int D_8014428C;
extern short D_8017A2B8;
extern int D_800D9FA0;
extern int D_800D6300;

extern int func_80002E80(int mode);

void func_800B35D0(int arg0, int arg1) {
    (void)arg0;
    (void)arg1;
    D_8014427E = 0;
    D_80144278 = 0;
    D_8014427A = 0;
    D_80144290 = 0;
    D_80144280 = func_80002E80(1);
    D_8014428C = 1;
    if (D_8017A2B8 != -1) {
        D_800D9FA0 = D_8017A2B8;
    } else {
        D_800D9FA0 = 1;
    }
    D_800D6300 = 0x18;
}
