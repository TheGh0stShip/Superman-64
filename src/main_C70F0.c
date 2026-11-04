typedef unsigned int u32;
typedef unsigned char u8;

typedef struct SchedulerClient SchedulerClient;

struct SchedulerClient {
    SchedulerClient *next;
    void *queue;
};

typedef struct {
    u8 pad0[0x260];
    SchedulerClient *clientList;
} Scheduler;

extern u32 func_800C0A10(u32 mask);

void *func_800C64F0(Scheduler *scheduler) {
    return (u8 *)scheduler + 0x78;
}

void func_800C64F8(Scheduler *scheduler, SchedulerClient *client) {
    SchedulerClient *current = scheduler->clientList;
    SchedulerClient *previous = 0;
    u32 mask;

    mask = func_800C0A10(1);
    while (current != 0) {
        if (current == client) {
            if (previous != 0) {
                previous->next = client->next;
            } else {
                scheduler->clientList = client->next;
            }
            break;
        }
        previous = current;
        current = current->next;
    }
    func_800C0A10(mask);
}
