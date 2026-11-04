typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct PiHandle PiHandle;

struct PiHandle {
    PiHandle *next;
    u8 type;
    u8 latency;
    u8 page_size;
    u8 release_duration;
    u8 pulse;
    u8 domain;
    u8 pad0A[2];
    u32 base_address;
    u32 speed;
};

extern PiHandle *D_800DB100[2];

extern u32 func_800C30E0(void *address);

s32 func_800CDFF0(PiHandle *handle, s32 direction, u32 device_address,
                  void *dram_address, u32 size) {
    u32 status;
    u32 domain;

    status = *(volatile u32 *)0xA4600010;
    while (status & 3) {
        status = *(volatile u32 *)0xA4600010;
    }

    domain = handle->domain;
    if (D_800DB100[domain] != handle) {
        PiHandle *current = D_800DB100[domain];

        if (domain == 0) {
            if (current->latency != handle->latency) {
                *(volatile u32 *)0xA4600014 = handle->latency;
            }
            if (current->page_size != handle->page_size) {
                *(volatile u32 *)0xA460001C = handle->page_size;
            }
            if (current->release_duration != handle->release_duration) {
                *(volatile u32 *)0xA4600020 = handle->release_duration;
            }
            if (current->pulse != handle->pulse) {
                *(volatile u32 *)0xA4600018 = handle->pulse;
            }
        } else {
            if (current->latency != handle->latency) {
                *(volatile u32 *)0xA4600024 = handle->latency;
            }
            if (current->page_size != handle->page_size) {
                *(volatile u32 *)0xA460002C = handle->page_size;
            }
            if (current->release_duration != handle->release_duration) {
                *(volatile u32 *)0xA4600030 = handle->release_duration;
            }
            if (current->pulse != handle->pulse) {
                *(volatile u32 *)0xA4600028 = handle->pulse;
            }
        }
        D_800DB100[domain] = handle;
    }

    *(volatile u32 *)0xA4600000 = func_800C30E0(dram_address);
    *(volatile u32 *)0xA4600004 = (handle->base_address | device_address) & 0x1FFFFFFF;

    switch (direction) {
        case 0:
            *(volatile u32 *)0xA460000C = size - 1;
            break;
        case 1:
            *(volatile u32 *)0xA4600008 = size - 1;
            break;
        default:
            return -1;
    }
    return 0;
}
