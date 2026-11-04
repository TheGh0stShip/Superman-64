typedef signed int s32;
typedef unsigned int u32;

extern s32 func_800CDAD0(void);
extern u32 func_800C30E0(void *address);
extern void func_800C3160(void *address, s32 size);
extern void func_800CD5C0(void *address, s32 size);

s32 func_800C3C00(s32 direction, void *dram_address) {
    if (func_800CDAD0()) {
        return -1;
    }
    if (direction == 1) {
        func_800C3160(dram_address, 0x40);
    }
    *(volatile u32 *)0xA4800000 = func_800C30E0(dram_address);
    if (direction == 0) {
        *(volatile u32 *)0xA4800004 = 0x1FC007C0;
    } else {
        *(volatile u32 *)0xA4800010 = 0x1FC007C0;
    }
    if (direction == 0) {
        func_800CD5C0(dram_address, 0x40);
    }
    return 0;
}
