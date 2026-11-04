typedef signed int s32;
typedef unsigned char u8;

typedef struct {
    u8 *base;
    u8 *current;
    s32 length;
    s32 allocation_count;
} ALHeap;

void *func_800D2FE0(const char *file, s32 line, ALHeap *heap, s32 count, s32 size) {
    s32 byte_count = (count * size + 15) & ~15;
    u8 *allocation = 0;

    if (heap->base + heap->length >= heap->current + byte_count) {
        allocation = heap->current;
        heap->current += byte_count;
    }
    return allocation;
}
