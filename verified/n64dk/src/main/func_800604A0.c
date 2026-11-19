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

M2C_UNK func_8005FBA4();                  /* extern */
M2C_UNK func_8005FCC0();                  /* extern */
extern s32 D_8013F608;
extern s32 D_8013F60C;
extern s32 D_8013F610;
extern s32 D_8013F61C;
extern f32 D_8013F658;

void func_800604A0(s32 *arg0, s32 arg1) {
    if (D_8013F610 == 0xD0) {
        D_8013F610 = 0x98;
        D_8013F61C = 1;
        return;
    }
    if (!(*arg0 & 1)) {
        if (D_8013F610 == 0x9A) {
            D_8013F610 = 0x1B;
            D_8013F60C = 0x35;
            D_8013F608 = 5;
            D_8013F61C = 1;
            D_8013F658 = 0.0f;
            return;
        }
        func_8005FBA4(arg0, arg1);
        return;
    }
    switch (D_8013F610) {                           /* irregular */
    case 0x1B:
        D_8013F61C = 1;
        D_8013F608 = 2;
        D_8013F60C = 0x34;
        D_8013F610 = 0x98;
        return;
    case 0x22:
        D_8013F610 = 0x98;
        D_8013F608 = 2;
        D_8013F60C = 0x34;
        D_8013F61C = 1;
        return;
    case 0x9A:
        if (*arg0 & 1) {
            D_8013F61C = 1;
            D_8013F608 = 2;
            D_8013F60C = 0x34;
            D_8013F610 = 0x98;
            return;
        }
        D_8013F610 = 0x1B;
        D_8013F60C = 0x35;
        D_8013F608 = 5;
        D_8013F61C = 1;
        D_8013F658 = 0.0f;
        return;
    default:
        func_8005FCC0(arg0, arg1);
        return;
    }
}
