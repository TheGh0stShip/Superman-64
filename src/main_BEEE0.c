typedef struct Node Node;

struct Node {
    Node *next;
    Node *previous;
};

extern void *D_800DA040;
extern void func_800D3A30(void);
extern void func_800C82A0(void *owner);

void func_800BE2E0(Node *node, Node *next) {
    node->next = next->next;
    node->previous = next;
    if (next->next != 0) {
        next->next->previous = node;
    }
    next->next = node;
}

void func_800BE304(void) {
    if (D_800DA040 != 0) {
        func_800D3A30();
        D_800DA040 = 0;
    }
}

void func_800BE33C(void *owner) {
    if (D_800DA040 == 0) {
        D_800DA040 = owner;
        func_800C82A0(owner);
    }
}
