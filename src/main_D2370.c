typedef unsigned char u8;
typedef signed short s16;

typedef struct {
    u8 pad[0x10];
    s16 state;
} Request;

extern Request *D_800DA080;
extern u8 D_800DA078;
extern int func_800CF750(void);
extern void func_800CF770(int);
extern void func_800BEBFC(void *);

void func_800D1770(void) {
    register int saved_status = func_800CF750();

    D_800DA080->state = 2;
    func_800BEBFC(&D_800DA078);
    func_800CF770(saved_status);
}
