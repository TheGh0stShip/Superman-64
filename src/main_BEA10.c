extern unsigned short D_800DA030;
extern unsigned short D_801443B0;
extern short D_801443D8;
extern short D_801443DA;
extern void *D_801443B8[];

extern void func_800BD95C(void *entry);

void func_800BDE10(void) {
    if (D_800DA030 >= D_801443B0) {
        D_800DA030 = 0;
        D_801443D8 = D_801443DA;
        D_801443DA = 0;
    }
    func_800BD95C(D_801443B8[D_800DA030++]);
    if (D_801443DA != 0) {
        D_801443D8 = D_801443DA;
    }
}
