typedef struct RuntimeObject {
    char pad_000[0x6C];
    int state_06C;
    char pad_070[0x34];
    int linked_index_A4;
    char pad_0A8[0x18];
    short linked_index_C0;
    char pad_0C2[0x20A];
} RuntimeObject;

extern RuntimeObject *D_8015FB9C;

void func_80018480(int object_index, int source_index) {
    int linked_index;

    linked_index = D_8015FB9C[source_index].linked_index_C0;
    if (linked_index >= 0 && object_index != linked_index &&
        D_8015FB9C[linked_index].state_06C >= 0) {
        D_8015FB9C[object_index].linked_index_A4 = linked_index;
    }
}
