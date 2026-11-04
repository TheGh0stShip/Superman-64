typedef struct Node {
    struct Node *next;
} Node;

typedef struct {
    unsigned char pad00[0x2C];
    Node *head;
} RuntimeState;

extern RuntimeState *D_800DA040;

Node *func_800C7FD0(void) {
    RuntimeState *state = D_800DA040;
    Node *result = 0;
    Node *node = state->head;

    if (node != 0) {
        result = node;
        state->head = node->next;
        node->next = 0;
    }
    return result;
}
