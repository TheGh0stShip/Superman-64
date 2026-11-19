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

M2C_UNK alLink();
M2C_UNK alUnlink();
extern u32 D_800D60D4;
extern s32 D_800D60D8;
extern void *D_800E7C84;
extern void *D_800E7C88;
void func_80000EA8(void)
{
  s32 pad0[2];
  void *sp1C;
  void *sp18;
  sp1C = D_800E7C84;
  if (D_800E7C84 != NULL)
  {
    do
    {
      sp18 = *((void **) (((s8 *) sp1C) + 0));
      if (((u32) ((*((s32 *) (((s8 *) sp1C) + 0xC))) + 1)) < ((u32) D_800D60D4))
      {
        if (D_800E7C84 == sp1C)
        {
          D_800E7C84 = *((void **) (((s8 *) sp1C) + 0));
        }
        alUnlink(sp1C);
        if (D_800E7C88 != NULL)
        {
          alLink(sp1C, D_800E7C88);
        }
        else
        {
          D_800E7C88 = sp1C;
          *((void **) (((s8 *) sp1C) + 0)) = NULL;
          *((s32 *) (((s8 *) sp1C) + 4)) = 0;
        }
      }
      sp1C = sp18;
    }
    while (sp1C != NULL);
  }
  D_800D60D8 = 0;
  D_800D60D4 += 1;
}

