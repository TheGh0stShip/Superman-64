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

M2C_UNK func_8002AF10();
extern M2C_UNK D_800D83E4;
extern f32 D_800DCB1C;
extern f32 D_800DCB20;
extern s32 D_8015F464;
extern M2C_UNK D_80274A50;
void func_8002B360(s32 arg0)
{
  func_8002AF10(arg0, 0);
  *((f32 *) (((s8 *) ((*((s32 *) ((M2C_UNK *) (((u8 *) (&D_800D83E4)) + (D_8015F464 * 4))))) + (arg0 * 0x3C))) + 4)) = (f32) D_800DCB1C;
  *((s32 *) (((s8 *) ((*((s32 *) ((M2C_UNK *) (((u8 *) (&D_800D83E4)) + (D_8015F464 * 4))))) + (arg0 * 0x3C))) + 0x14)) = 0x80284C98;
  *((s32 *) (((s8 *) ((*((s32 *) ((M2C_UNK *) (((u8 *) (&D_800D83E4)) + (D_8015F464 * 4))))) + (arg0 * 0x3C))) + 0x1C)) = 0x1002;
  *((s32 *) (((s8 *) ((*((s32 *) ((M2C_UNK *) (((u8 *) (&D_800D83E4)) + (D_8015F464 * 4))))) + (arg0 * 0x3C))) + 0x24)) = 4;
  *((f32 *) (((s8 *) ((*((s32 *) ((M2C_UNK *) (((u8 *) (&D_800D83E4)) + (D_8015F464 * 4))))) + (arg0 * 0x3C))) + 0x28)) = 360.0f;
  *((f32 *) (((s8 *) ((*((s32 *) ((M2C_UNK *) (((u8 *) (&D_800D83E4)) + (D_8015F464 * 4))))) + (arg0 * 0x3C))) + 0x2C)) = (f32) D_800DCB20;
  *((f32 *) (((s8 *) ((*((s32 *) ((M2C_UNK *) (((u8 *) (&D_800D83E4)) + (D_8015F464 * 4))))) + (arg0 * 0x3C))) + 0x30)) = -14.0f;
  *((f32 *) (((s8 *) ((*((s32 *) ((M2C_UNK *) (((u8 *) (&D_800D83E4)) + (D_8015F464 * 4))))) + (arg0 * 0x3C))) + 0x34)) = -15.0f;
  *((f32 *) (((s8 *) ((*((s32 *) ((M2C_UNK *) (((u8 *) (&D_800D83E4)) + (D_8015F464 * 4))))) + (arg0 * 0x3C))) + 0x38)) = -12.0f;
  *((s32 *) ((M2C_UNK *) (((u8 *) (&D_80274A50)) + (arg0 * 0x30)))) = 1;
}

