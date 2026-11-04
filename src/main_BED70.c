typedef unsigned int u32;

typedef struct Thread Thread;

struct Thread {
    Thread *next;
    int priority;
    Thread **queue;
    unsigned char pad0C[4];
    unsigned short state;
};

typedef struct {
    Thread *message_waiters;
    Thread *space_waiters;
    int valid_count;
    int first;
    int capacity;
    void **messages;
} MessageQueue;

extern Thread *D_800DA080;

extern u32 func_800CF750(void);
extern void func_800CF770(u32 mask);
extern void func_800BEBFC(Thread **queue);
extern Thread *func_800BED44(Thread **queue);
extern void func_800D33A0(Thread *thread);

int func_800BE170(MessageQueue *queue, void **message, int flags) {
    register u32 mask;

    mask = func_800CF750();
    while (queue->valid_count == 0) {
        if (flags == 0) {
            func_800CF770(mask);
            return -1;
        }
        D_800DA080->state = 8;
        func_800BEBFC(&queue->message_waiters);
    }

    if (message != 0) {
        *message = queue->messages[queue->first];
    }
    queue->first = (queue->first + 1) % queue->capacity;
    queue->valid_count--;

    if (queue->space_waiters->next != 0) {
        func_800D33A0(func_800BED44(&queue->space_waiters));
    }
    func_800CF770(mask);
    return 0;
}
