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

extern s32 D_8015F858;
extern M2C_UNK D_8015F85C;
extern M2C_UNK D_8015F860;
extern s32 D_8015FB9C;
s32 func_800689D0(s32 arg0, s32 arg1, f32 arg2)
{
  if (((f64) arg2) <= 10.0)
  {
    *((s32 *) ((M2C_UNK *) (((u8 *) (&D_8015F85C)) + (D_8015F858 * 0x10)))) = arg0;
    *((s32 *) ((M2C_UNK *) (((u8 *) (&D_8015F860)) + (D_8015F858 * 0x10)))) = arg1;
    *((s32 *) (((s8 *) (((s8 *) D_8015FB9C) + (arg1 * 0x2CC))) + 0xA4)) = arg0;
    D_8015F858 += 1;
    return 1;
  }
  return 0;
}

