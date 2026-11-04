typedef struct RuntimeObject {
    int unused_00;
    int next_index;
    char pad_08[0x64];
    int state_6C;
    char pad_70[0x25C];
} RuntimeObject;

extern int D_8015FB8C;
extern RuntimeObject *D_8015FB9C;

extern void func_80048404(int object_index);

void func_800344B0(int state) {
    int object_index;

    object_index = D_8015FB8C;
    while (object_index >= 0) {
        if (D_8015FB9C[object_index].state_6C == state) {
            func_80048404(object_index);
        }
        object_index = D_8015FB9C[object_index].next_index;
    }
}
