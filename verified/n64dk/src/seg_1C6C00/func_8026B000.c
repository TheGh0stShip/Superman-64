typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

typedef struct Object {
    u8 pad00[0x50];
    f32 value50;
    u8 pad54[0x10];
    s32 type64;
    u8 pad68[0x18];
    s32 index80;
    u8 pad84[0x248];
} Object;

extern Object *D_8015FB9C;

void func_8026B000(s32 arg0) {
    if (D_8015FB9C[arg0].type64 == 0x16) {
        D_8015FB9C[D_8015FB9C[arg0].index80].value50 -= 1.0f;
    }
}
