typedef struct Node Node;

struct Node {
    Node *next;
    Node *previous;
};

void func_800BE2B0(Node *node) {
    if (node->next != 0) {
        node->next->previous = node->previous;
    }
    if (node->previous != 0) {
        node->previous->next = node->next;
    }
}
