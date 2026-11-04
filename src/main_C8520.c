typedef signed int s32;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned char u8;

typedef struct {
    s16 type;
    u8 priority;
    u8 status;
    void *return_queue;
} MessageHeader;

typedef struct {
    MessageHeader header;
    void *dram_address;
    u32 device_address;
    u32 size;
    void *pi_handle;
} IoMessage;

extern s32 D_800DB0E0;

extern void *func_800CFC30(void);
extern s32 func_800CDB30(void *queue, void *message, s32 flag);
extern s32 func_800BDEA0(void *queue, void *message, s32 flag);

s32 func_800C7920(IoMessage *message, s32 priority, s32 direction,
                  u32 device_address, void *dram_address, u32 size,
                  void *return_queue) {
    register s32 result;

    if (!D_800DB0E0) {
        return -1;
    }

    if (direction == 0) {
        message->header.type = 11;
    } else {
        message->header.type = 12;
    }

    message->header.priority = priority;
    message->header.return_queue = return_queue;
    message->dram_address = dram_address;
    message->device_address = device_address;
    message->size = size;
    message->pi_handle = 0;

    if (priority == 1) {
        result = func_800CDB30(func_800CFC30(), message, 0);
    } else {
        result = func_800BDEA0(func_800CFC30(), message, 0);
    }

    return result;
}
