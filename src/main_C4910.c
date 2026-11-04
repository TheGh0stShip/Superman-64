typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern volatile u16 *D_800DB1F4;

extern u32 func_800CF750(void);
extern void func_800CF770(u32 status);
extern s32 func_800CDAD0(void);

void func_800C3D10(u8 enabled) {
    register u32 status = func_800CF750();

    if (enabled != 0) {
        *D_800DB1F4 |= 0x20;
    } else {
        *D_800DB1F4 &= ~0x20;
    }
    func_800CF770(status);
}

s32 func_800C3D80(u32 address, u32 *value) {
    if (func_800CDAD0()) {
        return -1;
    }
    *value = *(volatile u32 *)(address | 0xA0000000);
    return 0;
}
