typedef signed int s32;
typedef unsigned char u8;
typedef float f32;
typedef double f64;

typedef struct SupermanActor {
    u8 pad00[0xE4];
    f32 height;
    u8 padE8[0x1E4];
} SupermanActor;

extern f32 D_800D64F0;
extern f32 D_800D9354[][3];
extern SupermanActor *D_8015FB9C;

s32 func_80092554(s32 arg0, s32 arg1) {
    f32 spC;
    f32 *sp8;
    f32 sp4;

    spC = D_800D64F0;
    sp8 = D_800D9354[arg1];
    sp4 = *sp8;
    if ((((f64)D_8015FB9C[arg0].height - 100.0) * (f64)D_800D64F0) <
        (f64)sp4) {
        return 1;
    }
    return 0;
}
