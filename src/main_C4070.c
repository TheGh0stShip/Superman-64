typedef unsigned int u32;
typedef signed int s32;

extern u32 D_80000308;

s32 func_800C3470(u32 device_address, u32 *value) {
    register u32 status;

    status = *(volatile u32 *)0xA4600010;
    while (status & 3) {
        status = *(volatile u32 *)0xA4600010;
    }
    *value = *(volatile u32 *)((D_80000308 | device_address) | 0xA0000000);
    return 0;
}
