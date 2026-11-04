typedef signed short s16;
typedef unsigned char u8;

typedef struct Command Command;
typedef struct Event Event;

typedef struct Handler {
    u8 pad0[8];
    void (*dispatch)(struct Handler *, int, Command *, Event *);
} Handler;

typedef struct {
    u8 pad0[0xC];
    Handler *handler;
    u8 pad10[0xC8];
    int offset;
} Object;

struct Event {
    u8 pad0[8];
    Object *object;
};

struct Command {
    int value0;
    int position;
    s16 type;
    s16 padA;
    int valueC;
};

typedef struct {
    u8 pad0[0x1C];
    int base;
} Owner;

extern Command *func_800C7FD0(Owner *);

void func_800CD670(Owner *owner, Event *event, u8 value) {
    Command *command;

    if (event->object == 0) {
        return;
    }
    command = func_800C7FD0(owner);
    if (command != 0) {
        command->position = owner->base + event->object->offset;
        command->type = 16;
        command->valueC = value < 0 ? -value : value;
        command->value0 = 0;
        event->object->handler->dispatch(event->object->handler, 3, command,
                                         event);
    }
}
