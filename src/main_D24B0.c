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
    u8 padC[0xE];
    s16 value1A;
};

struct Command {
    int value0;
    int position;
    s16 type;
    s16 valueA;
    float valueC;
    s16 value10;
    u8 value12;
    u8 value13;
    int value14;
    int value18;
};

typedef struct {
    u8 pad0[0x1C];
    int base;
} Owner;

extern int func_800C7EC8(Owner *, int);
extern Command *func_800C7FD0(Owner *);

void func_800D18B0(Owner *owner, Event *event, int value18, float valueC,
                   s16 value10, u8 value12, u8 value13, int timing) {
    Command *command;

    if (event->object == 0) {
        return;
    }
    command = func_800C7FD0(owner);
    if (command != 0) {
        if (value13 < 0) {
            value13 = -value13;
        }
        command->position = owner->base + event->object->offset;
        command->value0 = 0;
        command->type = 13;
        command->valueA = event->value1A;
        command->value12 = value12;
        command->value10 = value10;
        command->value13 = value13;
        command->valueC = valueC;
        command->value14 = func_800C7EC8(owner, timing);
        command->value18 = value18;
        event->object->handler->dispatch(event->object->handler, 3, command,
                                         event);
    }
}
