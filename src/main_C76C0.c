typedef unsigned char u8;
typedef signed short s16;

typedef struct {
    u8 pad0[4];
    int value4;
} Source;

typedef struct {
    s16 state;
    u8 pad2[6];
    Source *source;
    int valueC;
} State;

extern State *D_800DB1F4;
extern void func_800D2F90(int);
extern int func_800CF750(void);
extern void func_800CF770(int);

void func_800C6AC0(void) {
    func_800D2F90(0x400);
}

void func_800C6AE0(Source *source) {
    register int saved_status = func_800CF750();

    D_800DB1F4->source = source;
    D_800DB1F4->state = 1;
    D_800DB1F4->valueC = D_800DB1F4->source->value4;
    func_800CF770(saved_status);
}
