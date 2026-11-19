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

s32 alAudioFrame();
M2C_UNK func_80000EA8();
u32 func_800D1470();
M2C_UNK osAiSetNextBuffer();
M2C_UNK osSendMesg();
s32 osVirtualToPhysical();
extern M2C_UNK D_800D3DB0;
extern M2C_UNK D_800D3E80;
extern M2C_UNK D_800D52B0;
extern s32 D_800D60DC;
extern M2C_UNK D_800E0730;
extern s32 D_800E59F4;
extern M2C_UNK D_800E59F8;
extern u32 D_800E8050;
extern s32 D_800E8054;
s32 func_800009A0(s8 *arg0, void *arg1)
{
  s32 sp2C;
  s32 sp28;
  s32 sp24;
  u32 sp20;
  s8 *sp1C;
  sp20 = 0;
  func_80000EA8();
  sp2C = osVirtualToPhysical(*((s32 *) (((s8 *) arg0) + 0)));
  if (arg1 != NULL)
  {
    osAiSetNextBuffer(*((s32 *) (((s8 *) arg1) + 0)), (*((s16 *) (((s8 *) arg1) + 4))) * 4);
  }
  sp20 = func_800D1470() >> 2;
  *((s16 *) (((s8 *) arg0) + 4)) = (s16) (((D_800E8054 - sp20) + 0x60) & (~0xF));
  if (((u32) (*((s16 *) (((s8 *) arg0) + 4)))) < ((u32) D_800E8050))
  {
    *((s16 *) (((s8 *) arg0) + 4)) = (s16) D_800E8050;
  }
  sp28 = alAudioFrame(*((s32 *) ((M2C_UNK *) (((u8 *) (&D_800E59F8)) + (D_800D60DC * 4)))), &sp24, sp2C, *((s16 *) (((s8 *) arg0) + 4)));
  if (sp24 == 0)
  {
    return 0;
  }
  sp1C = arg0 + 8;
  *((s32 *) (((s8 *) arg0) + 8)) = 0;
  *((void **) (((s8 *) sp1C) + 0x50)) = (void *) ((M2C_UNK *) (((u8 *) (&D_800E59F8)) + 0x200));
  *((void **) (((s8 *) sp1C) + 0x54)) = (void *) (arg0 + 0x70);
  *((s32 *) (((s8 *) sp1C) + 8)) = 2;
  *((s32 *) (((s8 *) sp1C) + 0x40)) = (s32) (*((s32 *) ((M2C_UNK *) (((u8 *) (&D_800E59F8)) + (D_800D60DC * 4)))));
  *((s32 *) (((s8 *) sp1C) + 0x44)) = (s32) ((((s32) (sp28 - (*((s32 *) ((M2C_UNK *) (((u8 *) (&D_800E59F8)) + (D_800D60DC * 4))))))) >> 3) * 8);
  *((s32 *) (((s8 *) sp1C) + 0x10)) = 2;
  *((M2C_UNK **) (((s8 *) sp1C) + 0x18)) = &D_800D3DB0;
  *((s32 *) (((s8 *) sp1C) + 0x1C)) = (s32) (((u8 *) (&D_800D3E80)) - ((u8 *) (&D_800D3DB0)));
  *((s32 *) (((s8 *) sp1C) + 0x14)) = 0;
  *((M2C_UNK **) (((s8 *) sp1C) + 0x20)) = &D_800D52B0;
  *((M2C_UNK **) (((s8 *) sp1C) + 0x28)) = &D_800E0730;
  *((s32 *) (((s8 *) sp1C) + 0x2C)) = 0x800;
  *((s32 *) (((s8 *) sp1C) + 0x30)) = 0;
  *((s32 *) (((s8 *) sp1C) + 0x34)) = 0;
  *((s32 *) (((s8 *) sp1C) + 0x38)) = 0;
  *((s32 *) (((s8 *) sp1C) + 0x3C)) = 0;
  *((s32 *) (((s8 *) sp1C) + 0x48)) = 0;
  *((s32 *) (((s8 *) sp1C) + 0x4C)) = 0;
  osSendMesg(D_800E59F4, sp1C, 1);
  D_800D60DC ^= 1;
  return 1;
}

