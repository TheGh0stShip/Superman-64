typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    int value4;
} State;

extern State *D_800DB1F0;
extern int func_800CF750(void);
extern void func_800CF770(int);

int func_800D3D00(void) {
    register u32 status = *(volatile u32 *)0xA450000C;

    if ((status & 0x80000000) != 0) {
        return 1;
    }
    return 0;
}

int func_800D3D30(void) {
    register int saved_status = func_800CF750();
    int value = D_800DB1F0->value4;

    func_800CF770(saved_status);
    return value;
}

int func_800D3D70(u32 address) {
    register u32 status = *(volatile u32 *)0xA4040010;

    if (!(status & 1)) {
        return -1;
    }
    *(volatile u32 *)0xA4080000 = address;
    return 0;
}
