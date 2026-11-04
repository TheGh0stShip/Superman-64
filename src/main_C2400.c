typedef unsigned char u8;

typedef struct RuntimeNode RuntimeNode;

struct RuntimeNode {
    RuntimeNode *next;
    char pad04[0x10];
    RuntimeNode *owner;
    char pad18[0x19];
    u8 first;
    u8 second;
    u8 third;
};

typedef struct {
    char pad00[0x64];
    RuntimeNode *head;
    RuntimeNode *tail;
    RuntimeNode *free;
} RuntimeQueue;

RuntimeNode *func_800C1800(RuntimeQueue *queue, u8 first, u8 second, u8 third) {
    RuntimeNode *node = queue->free;

    if (node != 0) {
        queue->free = node->next;
        node->next = 0;
        if (queue->head == 0) {
            queue->head = node;
        } else {
            queue->tail->next = node;
        }
        queue->tail = node;
        node->first = third;
        node->second = first;
        node->third = second;
        node->owner = node;
    }
    return node;
}
