typedef unsigned int u32;

typedef struct {
    u32 start;
    u32 current;
    u32 size;
    u32 used;
} AlignedBuffer;

void func_800CD250(AlignedBuffer *buffer, u32 address, u32 size) {
    u32 adjustment = 16 - (address & 15);

    if (adjustment != 16) {
        buffer->start = address + adjustment;
    } else {
        buffer->start = address;
    }
    buffer->current = buffer->start;
    buffer->size = size;
    buffer->used = 0;
}
