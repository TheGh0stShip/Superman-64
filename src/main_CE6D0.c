typedef unsigned int u32;

int func_800CDAD0(void) {
    register u32 status = *(volatile u32 *)0xA4800018;

    if ((status & 3) != 0) {
        return 1;
    }
    return 0;
}
