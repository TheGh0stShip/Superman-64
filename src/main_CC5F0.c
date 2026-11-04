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

PiHandle D_80146AE0;
extern PiHandle *D_800DB0FC;

extern int func_800C3470(void *device, u32 *value);
extern void func_800C3790(void *destination, int size);
extern u32 func_800CF750(void);
extern void func_800CF770(u32 mask);

PiHandle *func_800CB9F0(void) {
    u32 value = 0;
    u32 mask;

    if (D_80146AE0.base_address == 0xB0000000) {
        return &D_80146AE0;
    }

    D_80146AE0.type = 0;
    D_80146AE0.base_address = 0xB0000000;
    func_800C3470(0, &value);
    D_80146AE0.latency = value & 0xFF;
    D_80146AE0.pulse = (value >> 8) & 0xFF;
    D_80146AE0.page_size = (value >> 16) & 0xF;
    D_80146AE0.release = (value >> 20) & 0xF;
    D_80146AE0.domain = 0;
    D_80146AE0.speed = 0;

    func_800C3790(D_80146AE0.transfer_info, 0x60);

    mask = func_800CF750();
    D_80146AE0.next = D_800DB0FC;
    D_800DB0FC = &D_80146AE0;
    func_800CF770(mask);

    return &D_80146AE0;
}
