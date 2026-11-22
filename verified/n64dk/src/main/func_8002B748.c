typedef unsigned char u8;
typedef signed int s32;

typedef struct {
    u8 pad0[0x64];
    s32 state;
    s32 previousState;
    u8 pad6C[0x260];
} UnkObject;

extern UnkObject *D_8015FB9C;

void func_8002B748(s32 arg0) {
    UnkObject *object;

    object = &D_8015FB9C[arg0];
    switch (object->state) {
    case 0x30:
    case 0x37:
        object->previousState = 0x37;
        break;
    case 0x3B:
    case 0x3D:
    case 0x3E:
        object->state = object->previousState;
        break;
    default:
        object->previousState = 0xC;
        break;
    }
    object->state = 0xC;
}
