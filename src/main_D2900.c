typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned long long u64;

typedef struct PiHandle PiHandle;
typedef struct Timer Timer;

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

struct Timer {
    Timer *next;
    Timer *prev;
    u64 interval;
    u64 value;
    void *queue;
    void *message;
};

extern PiHandle *D_800DB100[2];
extern Timer *D_800DB180;

extern u64 func_800CE5F8(Timer *timer);
extern void func_800CE584(u64 time);

s32 func_800D1D00(PiHandle *handle, u32 device_address, u32 data) {
    register u32 status;
    register u32 domain;

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

    *(volatile u32 *)((handle->base_address | device_address) | 0xA0000000) = data;
    return 0;
}

s32 func_800D1E90(Timer *timer, u64 countdown, u64 interval, void *queue,
                  void *message) {
    u64 time;

    timer->next = 0;
    timer->prev = 0;
    timer->interval = interval;
    timer->value = countdown != 0 ? countdown : interval;
    timer->queue = queue;
    timer->message = message;

    time = func_800CE5F8(timer);
    if (D_800DB180->next == timer) {
        func_800CE584(time);
    }
    return 0;
}
