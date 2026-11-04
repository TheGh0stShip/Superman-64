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
extern void func_800BECFC(Thread **queue, Thread *thread);
extern Thread *func_800BED44(Thread **queue);
extern void func_800BED54(void);
extern void func_800BEBFC(Thread **queue);

void func_800D33A0(Thread *thread) {
    register u32 mask = func_800CF750();

    switch (thread->state) {
    case 8:
        thread->state = 2;
        func_800BECFC(&D_800DA078, thread);
        break;
    case 1:
        if (thread->queue == 0 || thread->queue == &D_800DA078) {
            thread->state = 2;
            func_800BECFC(&D_800DA078, thread);
        } else {
            thread->state = 8;
            func_800BECFC(thread->queue, thread);
            func_800BECFC(&D_800DA078, func_800BED44(thread->queue));
        }
        break;
    }

    if (D_800DA080 == 0) {
        func_800BED54();
    } else if (D_800DA080->priority < D_800DA078->priority) {
        D_800DA080->state = 2;
        func_800BEBFC(&D_800DA078);
    }
    func_800CF770(mask);
}
