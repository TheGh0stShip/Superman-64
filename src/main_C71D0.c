typedef signed int s32;
typedef signed short s16;
typedef unsigned char u8;

typedef struct {
    s16 type;
    u8 pad2[0x1E];
} SchedulerMessage;

typedef struct {
    u8 retraceMessage[0x20];
    SchedulerMessage prenmiMessage;
    u8 interruptQueue[0x18];
    u8 interruptBuffer[0x20];
    u8 commandQueue[0x18];
    u8 commandBuffer[0x20];
    u8 thread[0x1B0];
    void *clientList;
    void *audioListHead;
    void *graphicsListHead;
    void *audioListTail;
    void *graphicsListTail;
    void *currentRspTask;
    void *currentRdpTask;
    s32 frameCount;
} Scheduler;

typedef struct {
    u8 bytes[0x50];
} VideoMode;

extern VideoMode D_800DA0F0[];
extern void func_800C62C4(void *);
extern void func_800CD510(void *, void *, s32);
extern void func_800D35A0(s32);
extern void func_800C6AE0(VideoMode *);
extern void func_800C3D10(s32);
extern void func_800CC130(s32, void *, s32);
extern void func_800CFF90(void *, s32, u8);
extern void func_800BFCF0(void *, s32, void (*)(void *), void *, void *, s32);
extern void func_800D33A0(void *);

void func_800C65D0(Scheduler *scheduler, void *stack, s32 priority, u8 mode,
                   u8 fieldCount) {
    scheduler->currentRspTask = 0;
    scheduler->currentRdpTask = 0;
    scheduler->clientList = 0;
    scheduler->frameCount = 0;
    scheduler->audioListHead = 0;
    scheduler->graphicsListHead = 0;
    scheduler->audioListTail = 0;
    scheduler->graphicsListTail = 0;
    ((SchedulerMessage *)scheduler->retraceMessage)->type = 1;
    scheduler->prenmiMessage.type = 4;

    func_800CD510(scheduler->interruptQueue, scheduler->interruptBuffer, 8);
    func_800CD510(scheduler->commandQueue, scheduler->commandBuffer, 8);
    func_800D35A0(0xFE);
    func_800C6AE0(&D_800DA0F0[mode]);
    func_800C3D10(1);
    func_800CC130(4, scheduler->interruptQueue, 0x29B);
    func_800CC130(9, scheduler->interruptQueue, 0x29C);
    func_800CC130(14, scheduler->interruptQueue, 0x29D);
    func_800CFF90(scheduler->interruptQueue, 0x29A, fieldCount);
    func_800BFCF0(scheduler->thread, 4, func_800C62C4, scheduler, stack,
                  priority);
    func_800D33A0(scheduler->thread);
}
