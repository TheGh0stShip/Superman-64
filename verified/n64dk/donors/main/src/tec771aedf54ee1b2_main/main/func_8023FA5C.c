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

s32 alHeapDBAlloc();
M2C_UNK func_80244850();
extern M2C_UNK alEnvmixerParam;
extern M2C_UNK alEnvmixerPull;
void func_8023FA5C(void *arg0, s32 arg1)
{
  func_80244850(arg0, &alEnvmixerPull, &alEnvmixerParam, 4);
  *((s32 *) (((s8 *) arg0) + 0x14)) = alHeapDBAlloc(0, 0, arg1, 1, 0x50);
  *((s32 *) (((s8 *) arg0) + 0x38)) = 1;
  *((s32 *) (((s8 *) arg0) + 0x48)) = 0;
  *((s16 *) (((s8 *) arg0) + 0x1A)) = 1;
  *((s16 *) (((s8 *) arg0) + 0x28)) = 1;
  *((s16 *) (((s8 *) arg0) + 0x2E)) = 1;
  *((s16 *) (((s8 *) arg0) + 0x1C)) = 1;
  *((s16 *) (((s8 *) arg0) + 0x1E)) = 1;
  *((s16 *) (((s8 *) arg0) + 0x20)) = 0;
  *((s16 *) (((s8 *) arg0) + 0x22)) = 0;
  *((s16 *) (((s8 *) arg0) + 0x26)) = 1;
  *((s16 *) (((s8 *) arg0) + 0x24)) = 0;
  *((s32 *) (((s8 *) arg0) + 0x30)) = 0;
  *((s32 *) (((s8 *) arg0) + 0x34)) = 0;
  *((s16 *) (((s8 *) arg0) + 0x18)) = 0;
  *((s32 *) (((s8 *) arg0) + 0x3C)) = 0;
  *((s32 *) (((s8 *) arg0) + 0x40)) = 0;
  *((s32 *) (((s8 *) arg0) + 0x44)) = 0;
}

