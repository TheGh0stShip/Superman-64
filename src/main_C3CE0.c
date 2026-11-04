typedef unsigned int u32;

extern u32 func_800C5C60(void *address);

u32 func_800C30E0(void *address) {
    if ((u32)address >= 0x80000000 && (u32)address < 0xA0000000) {
        return (u32)address & 0x1FFFFFFF;
    } else if ((u32)address >= 0xA0000000 && (u32)address < 0xC0000000) {
        return (u32)address & 0x1FFFFFFF;
    } else {
        return func_800C5C60(address);
    }
}
