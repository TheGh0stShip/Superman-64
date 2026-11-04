extern short D_80144334;
extern unsigned int D_801631F4[];

extern void func_800B8ED8(int arg0);

void func_800BC5D0(void) {
    if (D_80144334 == 2 && D_801631F4[0] >= 2) {
        D_801631F4[0] = 0;
        func_800B8ED8(1);
    }
}

void func_800BC620(void) {
    if (D_80144334 == 2 && D_801631F4[20] >= 3 && D_801631F4[21] == 0) {
        D_801631F4[21] = 1;
        func_800B8ED8(1);
    }
}
