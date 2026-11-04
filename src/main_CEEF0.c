typedef unsigned int u32;
typedef unsigned long long u64;

extern u64 D_80146CB0;
extern u32 D_80146CB8;

extern u32 func_800CF750(void);
extern void func_800CF770(u32 mask);
extern u32 func_800C78B0(void);

u64 func_800CE2F0(void) {
    u32 count;
    u32 elapsed;
    u64 current;
    register u32 mask;

    mask = func_800CF750();
    count = func_800C78B0();
    elapsed = count - D_80146CB8;
    current = D_80146CB0;
    func_800CF770(mask);
    return current + elapsed;
}
