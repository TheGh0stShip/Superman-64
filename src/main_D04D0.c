typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u32 control;
    u32 width;
    u32 burst;
    u32 vertical_sync;
    u32 horizontal_sync;
    u32 leap;
    u32 horizontal_start;
    u32 x_scale;
    u32 vertical_current;
} ViCommonRegisters;

typedef struct {
    u32 origin;
    u32 y_scale;
    u32 vertical_start;
    u32 vertical_burst;
    u32 vertical_interrupt;
} ViFieldRegisters;

typedef struct {
    u8 type;
    ViCommonRegisters common;
    ViFieldRegisters fields[2];
} ViMode;

typedef struct {
    float factor;
    u16 offset;
    u16 pad06;
    u32 scale;
} ViScale;

typedef struct ViContext ViContext;

struct ViContext {
    u16 state;
    u16 retrace_count;
    void *frame_buffer;
    ViMode *mode;
    u32 control;
    void *message_queue;
    void *message;
    ViScale x;
    ViScale y;
};

extern ViContext *D_800DB1F0;
extern ViContext *D_800DB1F4;

extern u32 func_800C30E0(void *address);

void func_800CF8D0(void) {
    register ViMode *mode;
    register ViContext *context;
    u32 origin;
    u32 horizontal_start;
    u32 nominal_value;
    u32 field;

    field = 0;
    context = D_800DB1F4;
    mode = context->mode;

    field = *(volatile u32 *)0xA4400010 & 1;

    origin = func_800C30E0(context->frame_buffer) + mode->fields[field].origin;
    if (context->state & 2) {
        context->x.scale |= mode->common.x_scale & ~0xFFF;
    } else {
        context->x.scale = mode->common.x_scale;
    }

    if (context->state & 4) {
        nominal_value = mode->fields[field].y_scale & 0xFFF;
        context->y.scale = context->y.factor * nominal_value;
        context->y.scale |= mode->fields[field].y_scale & ~0xFFF;
    } else {
        context->y.scale = mode->fields[field].y_scale;
    }

    horizontal_start = mode->common.horizontal_start;
    if (context->state & 0x20) {
        horizontal_start = 0;
    }

    if (context->state & 0x40) {
        context->y.scale = 0;
        origin = func_800C30E0(context->frame_buffer);
    }

    if (context->state & 0x80) {
        context->y.scale = (context->y.offset << 16) & 0x03FF0000;
        origin = func_800C30E0(context->frame_buffer);
    }

    *(volatile u32 *)0xA4400004 = origin;
    *(volatile u32 *)0xA4400008 = mode->common.width;
    *(volatile u32 *)0xA4400014 = mode->common.burst;
    *(volatile u32 *)0xA4400018 = mode->common.vertical_sync;
    *(volatile u32 *)0xA440001C = mode->common.horizontal_sync;
    *(volatile u32 *)0xA4400020 = mode->common.leap;
    *(volatile u32 *)0xA4400024 = horizontal_start;
    *(volatile u32 *)0xA4400028 = mode->fields[field].vertical_start;
    *(volatile u32 *)0xA440002C = mode->fields[field].vertical_burst;
    *(volatile u32 *)0xA440000C = mode->fields[field].vertical_interrupt;
    *(volatile u32 *)0xA4400030 = context->x.scale;
    *(volatile u32 *)0xA4400034 = context->y.scale;
    *(volatile u32 *)0xA4400000 = context->control;

    D_800DB1F4 = D_800DB1F0;
    D_800DB1F0 = context;
    *D_800DB1F4 = *D_800DB1F0;
}
