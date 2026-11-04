typedef unsigned short u16;

typedef struct {
    u16 type;
    unsigned char pad02[14];
} Event;

typedef struct {
    unsigned char pad00[0x48];
    unsigned char queue[1];
} EventOwner;

extern void func_800C0C6C(void *queue, Event *event, int flags);

void func_800C38B0(EventOwner *owner) {
    Event event;

    event.type = 17;
    func_800C0C6C(owner->queue, &event, 0);
}
