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

M2C_UNK func_8002BC48();
s32 func_80048160();
M2C_UNK func_80048404();
M2C_UNK func_800826F0();
extern s16 D_801442E6;
extern s16 D_801442E8;
extern s16 D_80144348;
extern s16 D_8014434C;
extern s32 D_8015FB8C;
extern s32 D_8015FB9C;
extern s32 D_8015FF80;
extern s16 D_8017AB9C;
extern M2C_UNK D_801C5D40;
void func_800B9068(void)
{
  void *sp2C;
  s32 sp28;
  s32 sp24;
  if (D_8014434C != 0)
  {
    D_8014434C = 0;
    func_800826F0(*((s32 *) (((s8 *) (&D_801C5D40)) + 0x254)), 0, 0x30, -1, 0xA0, 0x50);
  }
  sp28 = D_8015FB8C;
  if (D_8015FB8C >= 0)
  {
    do
    {
      sp2C = (sp28 * 0x2CC) + D_8015FB9C;
      if (((*((s32 *) (((s8 *) sp2C) + 0x6C))) == 0x206) && ((*((s32 *) (((s8 *) sp2C) + 0x78))) < D_801442E8))
      {
        if (((*((s32 *) (((s8 *) sp2C) + 0x70))) & 0xFF000000) == 0x01000000)
        {
          D_80144348 = 1;
          func_8002BC48(0xF, 0, 0x5E, D_8015FF80);
          sp24 = func_80048160(0xF);
          if (sp24 != (-1))
          {
            *((s32 *) (((s8 *) (((s8 *) D_8015FB9C) + (sp24 * 0x2CC))) + 0x7C)) = 0;
          }
        }
        *((s32 *) (((s8 *) sp2C) + 0xC)) = 0;
        func_80048404(sp28);
        if ((*((s32 *) (((s8 *) sp2C) + 0x78))) == D_801442E6)
        {
          D_8017AB9C = 0;
        }
      }
      sp28 = *((s32 *) (((s8 *) sp2C) + 4));
    }
    while (sp28 >= 0);
  }
}

