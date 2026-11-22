typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;

typedef struct State {
    u8 pad00[0x4C];
    s16 value4C;
    s16 value4E;
    u8 pad50[0x14];
    s16 value64;
    s16 value66;
} State;

void func_800938C8(s32 arg0) {
    State *state;

    state = (State *)0x8030A118;
    if (arg0 != 0) {
        state->value4C = 0;
        state->value64 = 4;
        state->value4E = 4;
        state->value66 = 3;
    } else {
        state->value4E = 1;
        state->value66 = 1;
        state->value4C = 10;
        state->value64 = 11;
    }
}
