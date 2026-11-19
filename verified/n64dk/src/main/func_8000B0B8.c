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

M2C_UNK func_8000A5E0();               /* extern */
M2C_UNK func_8000AC3C();              /* extern */
M2C_UNK func_8000ADF8();              /* extern */
extern s32 D_8013B700;
extern s32 D_8013B704;
extern s32 D_8013B708;
extern f32 D_8013B710;
extern f32 D_8013B714;
extern s32 D_8013B720;
extern s32 D_8013B724;

void func_8000B0B8(void *arg0, void *arg1) {
    s32 pad[2];
    func_8000A5E0(arg0, &D_8013B700);
    func_8000A5E0(arg1, &D_8013B708);
    D_8013B720 = D_8013B700;
    D_8013B724 = D_8013B704;
    D_8013B710 = M2C_FIELD(arg1, f32 *, 0) - M2C_FIELD(arg0, f32 *, 0);
    D_8013B714 = M2C_FIELD(arg1, f32 *, 4) - M2C_FIELD(arg0, f32 *, 4);
    func_8000AC3C(arg0, arg1);
    func_8000ADF8(arg0, arg1);
}
