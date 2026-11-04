extern int D_800DA0C0;
extern int func_800CF750(void);
extern void func_800CF770(int);

void func_800CE970(int mask) {
    register int saved_status = func_800CF750();

    D_800DA0C0 |= mask;
    func_800CF770(saved_status);
}
