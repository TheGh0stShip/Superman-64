typedef struct Node Node;

struct Node {
    Node *next;
    Node *previous;
};

typedef struct {
    unsigned char pad00[4];
    Node *list04;
    unsigned char pad08[0xC];
    Node *list14;
} RuntimeObject;

typedef struct {
    unsigned char pad00[0x2C];
    Node *head;
} RuntimeState;

extern RuntimeState *D_800DA040;
extern void func_800BE2B0(Node *node);
extern void func_800BE2E0(Node *node, Node *next);

void func_800C7F20(RuntimeObject *object, Node *node) {
    func_800BE2B0(node);
    func_800BE2E0(node, (Node *)&object->list14);
}

void func_800C7F58(RuntimeObject *object) {
    Node *node;

    node = object->list14;
    while (node != 0) {
        func_800BE2B0(node);
        func_800BE2E0(node, (Node *)&object->list04);
        node = object->list14;
    }
}

void func_800C7FB8(Node *node) {
    RuntimeState *state = D_800DA040;

    node->next = state->head;
    state->head = node;
}
