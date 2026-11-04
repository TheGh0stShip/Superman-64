typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    u32 type;
    u32 flags;
    u64 *ucodeBoot;
    u32 ucodeBootSize;
    u64 *ucode;
    u32 ucodeSize;
    u64 *ucodeData;
    u32 ucodeDataSize;
    u64 *dramStack;
    u32 dramStackSize;
    u64 *outputBuffer;
    u64 *outputBufferSize;
    u64 *dataPointer;
    u32 dataSize;
    u64 *yieldDataPointer;
    u32 yieldDataSize;
} Task;

extern Task D_801458D0;
extern void func_800CEDC0(void *source, void *destination, u32 size);
extern u32 func_800C30E0(void *address);
extern void func_800C3160(void *address, u32 size);
extern void func_800D2F90(u32 value);
extern int func_800D3D70(u32 address);
extern int func_800C6A30(u32 direction, u32 deviceAddress, void *dramAddress,
                         u32 size);
extern int func_800CDB00(void);

Task *func_800C6700(Task *input) {
    Task *task = &D_801458D0;

    func_800CEDC0(input, task, sizeof(Task));
    if (task->ucode != 0) {
        task->ucode = (u64 *)func_800C30E0(task->ucode);
    }
    if (task->ucodeData != 0) {
        task->ucodeData = (u64 *)func_800C30E0(task->ucodeData);
    }
    if (task->dramStack != 0) {
        task->dramStack = (u64 *)func_800C30E0(task->dramStack);
    }
    if (task->outputBuffer != 0) {
        task->outputBuffer = (u64 *)func_800C30E0(task->outputBuffer);
    }
    if (task->outputBufferSize != 0) {
        task->outputBufferSize = (u64 *)func_800C30E0(task->outputBufferSize);
    }
    if (task->dataPointer != 0) {
        task->dataPointer = (u64 *)func_800C30E0(task->dataPointer);
    }
    if (task->yieldDataPointer != 0) {
        task->yieldDataPointer =
            (u64 *)func_800C30E0(task->yieldDataPointer);
    }
    return task;
}

void func_800C681C(Task *input) {
    Task *task = func_800C6700(input);

    if (task->flags & 1) {
        task->ucodeData = task->yieldDataPointer;
        task->ucodeDataSize = task->yieldDataSize;
        input->flags &= ~1;
        if (task->flags & 4) {
            task->ucode =
                *(u64 **)(((u32)input->yieldDataPointer + 0xC00 - 4) |
                          0xA0000000);
        }
    }

    func_800C3160(task, sizeof(Task));
    func_800D2F90(0x2B00);
    while (func_800D3D70(0x04001000) == -1) {
    }
    while (func_800C6A30(1, 0x04000FC0, task, sizeof(Task)) == -1) {
    }
    while (func_800CDB00() != 0) {
    }
    while (func_800C6A30(1, 0x04001000, task->ucodeBoot,
                         task->ucodeBootSize) == -1) {
    }
}

void func_800C69AC(Task *task) {
    (void)task;
    while (func_800CDB00() != 0) {
    }
    func_800D2F90(0x125);
}
