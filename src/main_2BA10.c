typedef struct {
    int unk0;
    int next;
    char pad08[0x1C];
    float unk24;
    char pad28[0x44];
    int state;
    char pad70[0x70];
    float x;
    float y;
    float z;
    char padEC[0x1E0];
} RuntimeObject;

extern int D_8015FB8C;
extern RuntimeObject *D_8015FB9C;

float func_8005A458(float x, float y, float z);

void func_8002AE10(float x, float y, float z) {
    int index = D_8015FB8C;
    RuntimeObject *object;

    while (index != -1) {
        object = &D_8015FB9C[index];
        if (object->state == 2 || object->state == 3) {
            if (func_8005A458(x - object->x,
                              y - object->y,
                              z - object->z) < 300.0f) {
                object->unk24 = -15.0f;
            }
        }
        index = object->next;
    }
}
