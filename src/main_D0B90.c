typedef unsigned char u8;
typedef signed short s16;

typedef struct {
    u8 pad0[2];
    s16 value2;
    u8 pad4[0xC];
    int value10;
    int value14;
} State;

extern State *D_800DB1F4;
extern int func_800CF750(void);
extern void func_800CF770(int);

void func_800CFF90(int arg0, int arg1, int arg2) {
    register int saved_status = func_800CF750();

    D_800DB1F4->value10 = arg0;
    D_800DB1F4->value14 = arg1;
    D_800DB1F4->value2 = arg2;
    func_800CF770(saved_status);
}
