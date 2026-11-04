typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u32 control;
} ViCommonRegisters;

typedef struct {
    u8 type;
    ViCommonRegisters common;
} ViMode;

typedef struct {
    u16 state;
    u16 retrace_count;
    void *frame_buffer;
    ViMode *mode;
    u32 control;
} ViContext;

extern ViContext *D_800DB1F4;

extern u32 func_800CF750(void);
extern void func_800CF770(u32 mask);

void func_800CFDD0(u32 features) {
    register u32 save_mask;

    save_mask = func_800CF750();

    if (features & 1) {
        D_800DB1F4->control |= 8;
    }
    if (features & 2) {
        D_800DB1F4->control &= ~8;
    }
    if (features & 4) {
        D_800DB1F4->control |= 4;
    }
    if (features & 8) {
        D_800DB1F4->control &= ~4;
    }
    if (features & 0x10) {
        D_800DB1F4->control |= 0x10;
    }
    if (features & 0x20) {
        D_800DB1F4->control &= ~0x10;
    }
    if (features & 0x40) {
        D_800DB1F4->control |= 0x10000;
        D_800DB1F4->control &= ~0x300;
    }
    if (features & 0x80) {
        D_800DB1F4->control &= ~0x10000;
        D_800DB1F4->control |= D_800DB1F4->mode->common.control & 0x300;
    }

    D_800DB1F4->state |= 8;
    func_800CF770(save_mask);
}
