typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u32 pad00;
    u32 control;
} ViMode;

typedef struct {
    u16 state;
    u16 retrace_count;
    void *frame_buffer;
    ViMode *mode;
    u32 control;
    void *message_queue;
    void *message;
    u8 scales[0x18];
} ViContext;

extern ViContext D_800DB190[2];
extern ViContext *D_800DB1F0;
extern ViContext *D_800DB1F4;
extern u32 D_80000300;
extern ViMode D_800DB200;
extern ViMode D_800DB250;
extern ViMode D_800DB2A0;

extern void func_800C3790(void *address, int size);
extern void func_800CF8D0(void);

void func_800CF790(void) {
    func_800C3790(D_800DB190, sizeof(D_800DB190));
    D_800DB1F0 = &D_800DB190[0];
    D_800DB1F4 = &D_800DB190[1];
    D_800DB1F4->retrace_count = 1;
    D_800DB1F0->retrace_count = 1;
    D_800DB1F4->frame_buffer = (void *)0x80000000;
    D_800DB1F0->frame_buffer = (void *)0x80000000;

    if (D_80000300 == 0) {
        D_800DB1F4->mode = &D_800DB200;
    } else if (D_80000300 == 2) {
        D_800DB1F4->mode = &D_800DB2A0;
    } else {
        D_800DB1F4->mode = &D_800DB250;
    }

    D_800DB1F4->state = 0x20;
    D_800DB1F4->control = D_800DB1F4->mode->control;

    while (*(volatile u32 *)0xA4400010 > 10) {
    }

    *(volatile u32 *)0xA4400000 = 0;
    func_800CF8D0();
}
