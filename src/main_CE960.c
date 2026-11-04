typedef struct Thread Thread;

struct Thread {
    Thread *next;
    int priority;
};

extern Thread *D_800DA080;

int func_800CDD60(Thread *thread) {
    if (thread == 0) {
        thread = D_800DA080;
    }
    return thread->priority;
}
