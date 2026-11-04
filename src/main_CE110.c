typedef struct {
    void *start;
    void *current;
    int field8;
    int fieldC;
    int field10;
    int field14;
} State;

extern int D_800DA070;

void func_800CD510(State *state, int arg1, int arg2) {
    state->start = &D_800DA070;
    state->current = &D_800DA070;
    state->field8 = 0;
    state->fieldC = 0;
    state->field10 = arg2;
    state->field14 = arg1;
}
