typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    int value4;
} State;

extern State *D_800DB1F4;
extern int func_800CF750(void);
extern void func_800CF770(int);
extern int func_800CDB00(void);
extern u32 func_800C30E0(void *address);

int func_800C69F0(void) {
    register int saved_status = func_800CF750();
    int value = D_800DB1F4->value4;

    func_800CF770(saved_status);
    return value;
}

int func_800C6A30(int direction, u32 device_address, void *dram_address,
                  u32 size) {
    if (func_800CDB00()) {
        return -1;
    }

    *(volatile u32 *)0xA4040000 = device_address;
    *(volatile u32 *)0xA4040004 = func_800C30E0(dram_address);

    if (direction == 0) {
        *(volatile u32 *)0xA404000C = size - 1;
    } else {
        *(volatile u32 *)0xA4040008 = size - 1;
    }
    return 0;
}
