typedef unsigned char u8;
typedef unsigned int u32;

typedef struct PiHandle PiHandle;
struct PiHandle {
    PiHandle *next;
    u8 type;
    u8 latency;
    u8 page_size;
    u8 release;
    u8 pulse;
    u8 domain;
    u8 padA[2];
    u32 base_address;
    u32 speed;
    u8 transfer_info[0x60];
};

PiHandle D_80146C00;
extern PiHandle *D_800DB0FC;
PiHandle *D_80146C74;

extern void func_800C3790(void *destination, int size);
extern u32 func_800CF750(void);
extern void func_800CF770(u32 mask);

PiHandle *func_800CD290(void) {
    u32 mask;

    D_80146C00.type = 2;
    D_80146C00.base_address = 0xA5000000;
    D_80146C00.latency = 3;
    D_80146C00.pulse = 6;
    D_80146C00.page_size = 6;
    D_80146C00.release = 2;
    D_80146C00.domain = 1;

    *(volatile u32 *)0xA4600024 = 3;
    *(volatile u32 *)0xA4600028 = D_80146C00.pulse;
    *(volatile u32 *)0xA460002C = D_80146C00.page_size;
    *(volatile u32 *)0xA4600030 = D_80146C00.release;

    D_80146C00.speed = 0;
    func_800C3790(D_80146C00.transfer_info, 0x60);

    mask = func_800CF750();
    D_80146C00.next = D_800DB0FC;
    D_800DB0FC = &D_80146C00;
    D_80146C74 = &D_80146C00;
    func_800CF770(mask);

    return &D_80146C00;
}
