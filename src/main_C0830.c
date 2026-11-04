extern int D_800DA0A0;
extern char D_80145470[];
extern char D_80145478[];

extern void func_800BDEA0(void *, int, int);
extern void func_800BE170(void *, void *, int);
extern void func_800CD510(void *, void *, int);

void func_800BFC30(void) {
    D_800DA0A0 = 1;
    func_800CD510(D_80145478, D_80145470, 1);
    func_800BDEA0(D_80145478, 0, 0);
}

void func_800BFC80(void) {
    int value;

    if (D_800DA0A0 == 0) {
        func_800BFC30();
    }
    func_800BE170(D_80145478, &value, 1);
}

void func_800BFCC4(void) {
    func_800BDEA0(D_80145478, 0, 0);
}
