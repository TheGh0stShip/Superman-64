typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Node {
    struct Node *next;
    u8 pad4[0xC];
    int value10;
} Node;

typedef struct {
    Node *head;
    u8 pad4[0x1C];
    int value20;
} List;

extern u32 func_800C0A10(u32 mask);

void func_800D0060(List *list, Node *node) {
    u32 mask = func_800C0A10(1);

    node->value10 = list->value20;
    node->next = list->head;
    list->head = node;
    func_800C0A10(mask);
}
