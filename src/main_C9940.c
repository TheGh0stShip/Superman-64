typedef unsigned char u8;

typedef struct {
    u8 pad0[0x14];
    int count;
    u8 pad18[4];
    void **items;
} List;

int func_800C8D40(List *list, int operation, void *item) {
    void **items = list->items;

    if (operation == 2) {
        items[list->count] = item;
        list->count++;
    }
    return 0;
}
