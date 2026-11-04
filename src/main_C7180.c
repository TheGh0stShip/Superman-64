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

void func_800C6580(Scheduler *scheduler, SchedulerClient *client, void *queue) {
    u32 mask;

    mask = func_800C0A10(1);
    client->queue = queue;
    client->next = scheduler->clientList;
    scheduler->clientList = client;
    func_800C0A10(mask);
}
