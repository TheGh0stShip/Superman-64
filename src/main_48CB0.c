typedef struct RuntimeObject {
    int unused_00;
    int next_index;
    char pad_08[0x68];
    int value_70;
    char pad_74[0x258];
} RuntimeObject;

extern int D_8015FB8C;
extern RuntimeObject *D_8015FB9C;

int func_800480B0(int value) {
    int object_index;

    object_index = D_8015FB8C;
    while (object_index >= 0) {
        if (D_8015FB9C[object_index].value_70 == value) {
            return object_index;
        }
        object_index = D_8015FB9C[object_index].next_index;
    }
    return -1;
}
