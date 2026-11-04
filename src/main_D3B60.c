typedef unsigned int u32;

int func_800D2F60(void) {
    register u32 status = *(volatile u32 *)0xA410000C;

    if ((status & 0x100) != 0) {
        return 1;
    }
    return 0;
}
