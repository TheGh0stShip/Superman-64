typedef struct RuntimeNode RuntimeNode;

struct RuntimeNode {
    RuntimeNode *next;
};

typedef struct {
    char pad00[0x64];
    RuntimeNode *head;
    RuntimeNode *tail;
    RuntimeNode *free;
} RuntimeQueue;

void func_800C1580(RuntimeQueue *queue, void *value) {
    RuntimeNode *previous = 0;
    RuntimeNode *node = queue->head;
    RuntimeNode *target = (RuntimeNode *)((char *)value - 4);

    while (node != 0) {
        if (node == target) {
            if (previous != 0) {
                previous->next = node->next;
            } else {
                queue->head = node->next;
            }
            if (node == queue->tail) {
                queue->tail = previous;
            }
            node->next = queue->free;
            queue->free = node;
            return;
        }
        previous = node;
        node = node->next;
    }
}
