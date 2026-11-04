typedef struct Node Node;

struct Node {
    Node *next;
};

void func_800BEEE0(Node **head, Node *node) {
    register Node **link = head;
    register Node *current = *link;

    while (current != 0) {
        if (current == node) {
            *link = node->next;
            break;
        }
        link = &current->next;
        current = *link;
    }
}
