typedef unsigned int u32;
typedef signed int s32;

extern s32 func_800CDAD0(void);

s32 func_800D2E60(u32 address, u32 value) {
    if (func_800CDAD0()) {
        return -1;
    }
    *(volatile u32 *)(address | 0xA0000000) = value;
    return 0;
}
