typedef struct {
    char pad00[0xC4];
    void *valueC4;
} RuntimeData;

extern int D_800D9E18;
extern int D_800D6248;
extern short D_8017A2C0;
extern short D_8017A2C8;
extern RuntimeData D_8017A028[];

extern int func_80002B70(int arg0);
extern void func_80002E38(int arg0);
extern void func_8000277C(int, void *, int, int, int);

void func_80093B70(void) {
    if (D_800D9E18 != 0 && (D_800D6248 & 7) == 0 &&
        func_80002B70(0x31) == 0) {
        func_80002E38(D_8017A2C0);
        D_800D9E18 = 0;
    }
}

void func_80093BD0(void) {
    func_80002E38(0);
    D_800D9E18 = 1;
    func_8000277C(0x31, D_8017A028[0].valueC4, D_8017A2C8, 0x40, 0);
}
