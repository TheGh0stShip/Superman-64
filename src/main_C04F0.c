typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    void *start;
    void *current;
    int field8;
    int fieldC;
    int field10;
    int field14;
} Queue;

typedef struct {
    u32 words[8];
} Timer;

extern int D_800DA090;
extern u8 D_801453E0[];
extern u8 D_80145420;
extern u8 D_80145421;
extern char D_80145448[];
extern char D_80145460[];

extern u64 func_800CE2F0(void);
extern void func_800CD510(void *, void *, int);
extern void func_800D1E90(Timer *, u64, u64, Queue *, void *);
extern int func_800BE170(void *, void **, int);
extern int func_800C3C00(int, void *);
extern void func_800BFB30(u8);
extern void func_800BFA60(void *, void *);
extern void func_800BFC30(void);

int func_800BF8F0(void *queue, void *result_mask, void *entries) {
    void *message;
    int result = 0;
    u64 now;
    Timer timer;
    Queue delay_queue;

    if (D_800DA090 != 0) {
        return 0;
    }
    D_800DA090 = 1;

    now = func_800CE2F0();
    if (now < 0x165A0BCULL) {
        func_800CD510(&delay_queue, &message, 1);
        func_800D1E90(&timer, 0x165A0BCULL - now, 0, &delay_queue, &message);
        func_800BE170(&delay_queue, &message, 1);
    }

    D_80145421 = 4;
    func_800BFB30(0);
    result = func_800C3C00(1, D_801453E0);
    func_800BE170(queue, &message, 1);
    result = func_800C3C00(0, D_801453E0);
    func_800BE170(queue, &message, 1);
    func_800BFA60(result_mask, entries);
    D_80145420 = 0;
    func_800BFC30();
    func_800CD510(D_80145448, D_80145460, 1);
    return result;
}
