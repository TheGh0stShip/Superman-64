typedef unsigned int u32;

typedef struct {
    unsigned short state;
    unsigned char pad02[2];
    void *framebuffer;
} ViContext;

extern ViContext *D_800DB1F4;

extern u32 func_800CF750(void);
extern void func_800CF770(u32 mask);

void func_800CDD80(void *framebuffer) {
    u32 mask;

    mask = func_800CF750();
    D_800DB1F4->framebuffer = framebuffer;
    D_800DB1F4->state |= 0x10;
    func_800CF770(mask);
}
