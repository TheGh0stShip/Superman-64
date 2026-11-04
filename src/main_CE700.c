typedef unsigned int u32;

int func_800CDB00(void) {
    register u32 status = *(volatile u32 *)0xA4040010;

    if ((status & 0x1C) != 0) {
        return 1;
    }
    return 0;
}
