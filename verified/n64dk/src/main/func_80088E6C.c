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

M2C_UNK func_80088B70();
s32 guRandom();
extern s32 D_800D6300;
extern s32 D_800D8C38;
extern M2C_UNK D_801425D0;
extern M2C_UNK D_801425D2;
extern M2C_UNK D_801425D4;
extern M2C_UNK D_801425D6;
extern M2C_UNK D_801425D8;
extern M2C_UNK D_801425DC;
extern M2C_UNK D_801425E0;
extern M2C_UNK D_801425E4;
extern M2C_UNK D_801425E8;
extern M2C_UNK D_801425EC;
extern M2C_UNK D_801425F0;
extern M2C_UNK D_801425F4;
s32 func_80088E6C(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5)
{
  s32 sp1C;
  if (D_800D6300 != 4)
  {
    *((f32 *) ((M2C_UNK *) (((u8 *) (&D_801425D8)) + (D_800D8C38 * 0x28)))) = arg4;
    *((s16 *) ((M2C_UNK *) (((u8 *) (&D_801425D6)) + (D_800D8C38 * 0x28)))) = (s16) arg5;
    *((s16 *) ((M2C_UNK *) (((u8 *) (&D_801425D0)) + (D_800D8C38 * 0x28)))) = (s16) arg0;
    if (arg0 == 1)
    {
      *((f32 *) ((M2C_UNK *) (((u8 *) (&D_801425E8)) + (D_800D8C38 * 0x28)))) = 180.0f;
    }
    else
    {
      *((f32 *) ((M2C_UNK *) (((u8 *) (&D_801425E8)) + (D_800D8C38 * 0x28)))) = (f32) (guRandom() % 360);
    }
    *((s16 *) ((M2C_UNK *) (((u8 *) (&D_801425D2)) + (D_800D8C38 * 0x28)))) = 0;
    *((s16 *) ((M2C_UNK *) (((u8 *) (&D_801425D4)) + (D_800D8C38 * 0x28)))) = 0;
    *((f32 *) ((M2C_UNK *) (((u8 *) (&D_801425DC)) + (D_800D8C38 * 0x28)))) = arg1;
    *((f32 *) ((M2C_UNK *) (((u8 *) (&D_801425E0)) + (D_800D8C38 * 0x28)))) = arg2;
    *((f32 *) ((M2C_UNK *) (((u8 *) (&D_801425E4)) + (D_800D8C38 * 0x28)))) = arg3;
    *((f32 *) ((M2C_UNK *) (((u8 *) (&D_801425EC)) + (D_800D8C38 * 0x28)))) = 10.0f;
    *((f32 *) ((M2C_UNK *) (((u8 *) (&D_801425F0)) + (D_800D8C38 * 0x28)))) = 0.0f;
    *((f32 *) ((M2C_UNK *) (((u8 *) (&D_801425F4)) + (D_800D8C38 * 0x28)))) = 0.0f;
    sp1C = D_800D8C38;
    func_80088B70();
    return sp1C;
  }
  return D_800D8C38;
}

