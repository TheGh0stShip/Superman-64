typedef unsigned int u32;
typedef unsigned long long u64;

extern int func_800D2F60(void);
extern u32 func_800C30E0(void *address);

int func_800D2EB0(void *buffer, u64 size) {
    register u32 status;

    if (func_800D2F60() != 0) {
        return -1;
    }

    *(volatile u32 *)0xA410000C = 1;
    while (1) {
        status = *(volatile u32 *)0xA410000C;
        if ((status & 1) == 0) {
            break;
        }
    }
    *(volatile u32 *)0xA4100000 = func_800C30E0(buffer);
    *(volatile u32 *)0xA4100004 = func_800C30E0(buffer) + size;
    return 0;
}
