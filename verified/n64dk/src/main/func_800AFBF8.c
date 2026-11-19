#ifndef N64DK_M2C_PRELUDE
#define N64DK_M2C_PRELUDE
typedef signed char s8; typedef unsigned char u8; typedef signed short s16; typedef unsigned short u16;
typedef signed int s32; typedef unsigned int u32; typedef signed long long s64; typedef unsigned long long u64;
typedef float f32; typedef double f64;
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
/* unhandled instructions become calls to an unprototyped function: any argument list compiles */
extern s32 m2c_unhandled();
#define M2C_ERROR m2c_unhandled
#define M2C_TRAP_IF m2c_unhandled
#define M2C_BREAK m2c_unhandled
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)
#define MULT_HI(a, b) ((s32)(((s64)(a) * (s64)(b)) >> 32))
#define MULTU_HI(a, b) ((u32)(((u64)(a) * (u64)(b)) >> 32))
#define M2C_CARRY 0
#ifndef NULL
#define NULL ((void *)0)
#endif
#endif

extern f32 D_800D7FD8;
extern f32 D_800D7FDC;
extern f32 D_800DF1AC;
extern f32 D_800DF1B0;
extern f32 D_801409C8;
extern f32 D_801409CC;
extern f32 D_801409D0;
extern f32 D_801409D4;
extern f32 D_801409D8;
extern f32 D_801409DC;
extern f32 D_801409E0;
extern f32 D_801409E4;
extern s32 D_80179A8C;
extern f32 D_80179AF4;
extern f32 D_80179AF8;
extern f32 D_80179B00;
extern f32 D_80179B04;
extern f32 D_8017F310;
extern f32 D_8017F314;
extern f32 D_8017F318;
extern f32 D_8017F31C;
extern f32 D_8017F320;
extern f32 D_8017F338;
extern f32 D_8017F33C;
extern f32 D_8017F340;
extern f32 D_8017F348;
extern f32 D_8017F34C;
extern f32 D_8017F350;

void func_800AFBF8(void) {
    D_800D7FDC = D_800DF1AC;
    D_800D7FD8 = 80.0f;
    D_8017F310 = 0.0f;
    D_8017F314 = 0.0f;
    D_8017F318 = 0.0f;
    D_8017F31C = D_800DF1B0;
    D_8017F320 = 0.0f;
    D_801409C8 = 0.0f;
    D_801409CC = 0.0f;
    D_801409D0 = 1000.0f;
    D_801409D4 = 0.0f;
    D_801409D8 = 0.0f;
    D_801409DC = 0.0f;
    D_801409E4 = 90.0f;
    D_801409E0 = 0.0f;
    D_80179A8C = 1;
    D_8017F338 = 0.0f;
    D_8017F33C = 0.0f;
    D_8017F340 = 1000.0f;
    D_8017F348 = 50.0f;
    D_8017F34C = 220.0f;
    D_8017F350 = 0.0f;
    D_80179B00 = 10.0f;
    D_80179B04 = 0.0f;
    D_80179AF4 = 0.0f;
    D_80179AF8 *= -1.0f;
    if (D_80179AF8 < 0.0f) {
        D_8017F348 *= -1.0f;
    }
}
