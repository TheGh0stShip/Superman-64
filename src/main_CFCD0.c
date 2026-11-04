typedef unsigned int u32;

extern u32 D_800DA0C0;
extern u32 func_800CF750(void);
extern void func_800CF770(u32 mask);

void func_800CF0D0(u32 mask) {
    register u32 saved_mask = func_800CF750();

    D_800DA0C0 &= ~(mask & ~0x401);
    func_800CF770(saved_mask);
}
