typedef signed int s32;
typedef unsigned char u8;

typedef struct Actor {
    u8 pad00[0x14];
    s32 linkedIndex;
    u8 pad18[0x40];
    s32 flags;
    u8 pad5C[8];
    s32 state;
    u8 pad68[4];
    s32 type;
    u8 rest[0x25C];
} Actor;

extern Actor *D_8015FB9C;

void func_8002A290(s32 arg0) {
    Actor *actor;
    Actor *linked;
    actor = &D_8015FB9C[arg0];
    if (actor->type == 0x1A && actor->linkedIndex != -1 && (actor->flags & 4)) {
        linked = &D_8015FB9C[actor->linkedIndex];
        if (linked->type == 0x54) {
            linked->state = 0x63;
            linked->linkedIndex = -1;
            actor->linkedIndex = -1;
        }
    }
}
