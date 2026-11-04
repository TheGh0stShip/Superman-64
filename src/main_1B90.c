extern unsigned char D_800E85C0[];
extern unsigned char D_800E85D8[];
extern void func_800CD510(void *state, void *storage, int count);

void func_80000F90(void) {
    func_800CD510(D_800E85C0, D_800E85D8, 1);
}
