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

extern M2C_UNK D_800D84F4;
extern M2C_UNK D_80143E70;
extern M2C_UNK D_80143E74;
extern M2C_UNK D_80143E78;
extern M2C_UNK D_80143EB0;
extern M2C_UNK D_80143EB4;
extern M2C_UNK D_80143EB8;
void func_80092600(void *arg0, void *arg1, s32 arg2)
{
  *((s32 *) ((M2C_UNK *) (((u8 *) (&D_800D84F4)) + (arg2 * 4)))) = 1;
  *((f32 *) ((M2C_UNK *) (((u8 *) (&D_80143E70)) + (arg2 * 0xC)))) = *((f32 *) (((s8 *) arg0) + 0));
  *((f32 *) ((M2C_UNK *) (((u8 *) (&D_80143E74)) + (arg2 * 0xC)))) = *((f32 *) (((s8 *) arg0) + 4));
  *((f32 *) ((M2C_UNK *) (((u8 *) (&D_80143E78)) + (arg2 * 0xC)))) = *((f32 *) (((s8 *) arg0) + 8));
  *((f32 *) ((M2C_UNK *) (((u8 *) (&D_80143EB0)) + (arg2 * 0xC)))) = *((f32 *) (((s8 *) arg1) + 0));
  *((f32 *) ((M2C_UNK *) (((u8 *) (&D_80143EB4)) + (arg2 * 0xC)))) = *((f32 *) (((s8 *) arg1) + 4));
  *((f32 *) ((M2C_UNK *) (((u8 *) (&D_80143EB8)) + (arg2 * 0xC)))) = *((f32 *) (((s8 *) arg1) + 8));
}

