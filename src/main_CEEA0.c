typedef signed short s16;
typedef signed int s32;

typedef struct {
    unsigned char pad00[0x1C];
    void *sound;
    unsigned char pad20[8];
    s32 state;
    unsigned char pad2C[4];
} SoundState;

typedef struct {
    unsigned char pad00[0x3C];
    s32 active_index;
    SoundState *states;
} Context;

void func_800CE2A0(Context *context, s16 index) {
    SoundState *states = context->states;

    if ((states + index)->state != 0) {
        return;
    }
    states[index].sound = 0;
    if (index == context->active_index) {
        context->active_index = -1;
    }
}
