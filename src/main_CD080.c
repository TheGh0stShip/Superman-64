typedef signed int s32;
typedef unsigned int u32;

s32 func_800CC480(void) {
    static u32 seed = 174823885;
    u32 x;

    x = (seed << 2) + 2;

    x *= x + 1;
    x = x >> 2;

    seed = x;

    return x;
}
