typedef unsigned int u32;

typedef struct Thread Thread;

struct Thread {
    Thread *next;
    int priority;
    Thread **queue;
    unsigned char pad0C[4];
    unsigned short state;
};

extern Thread *D_800DA078;
extern Thread *D_800DA080;

extern u32 func_800CF750(void);
extern void func_800CF770(u32 mask);
extern void func_800BEEE0(Thread **queue, Thread *thread);
extern void func_800BECFC(Thread **queue, Thread *thread);
extern void func_800BEBFC(Thread **queue);

void func_800CDC80(Thread *thread, int priority) {
    register u32 mask;

    mask = func_800CF750();
    if (thread == 0) {
        thread = D_800DA080;
    }
    if (thread->priority != priority) {
        thread->priority = priority;
        if (thread != D_800DA080 && thread->state != 1) {
            func_800BEEE0(thread->queue, thread);
            func_800BECFC(thread->queue, thread);
        }
        if (D_800DA080->priority < D_800DA078->priority) {
            D_800DA080->state = 2;
            func_800BEBFC(&D_800DA078);
        }
    }
    func_800CF770(mask);
}
