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

M2C_UNK func_80002AF0();                     /* extern */
M2C_UNK func_80002E38();                         /* extern */
extern s32 D_800D9D9C;
extern s32 D_800D9E18;
extern s16 D_8017A2C0;

void func_80094184(void) {
    func_80002AF0(3);
    func_80002AF0(4);
    func_80002AF0(5);
    func_80002AF0(6);
    func_80002AF0(7);
    func_80002AF0(0x12);
    func_80002AF0(0x1C);
    func_80002AF0(0x22);
    func_80002AF0(0x24);
    func_80002AF0(0x25);
    func_80002AF0(0x26);
    func_80002AF0(0x27);
    func_80002AF0(0x2A);
    func_80002AF0(0x33);
    func_80002AF0(0x34);
    func_80002AF0(0x47);
    func_80002AF0(0x48);
    func_80002AF0(0x4A);
    func_80002AF0(0x52);
    func_80002AF0(0x31);
    if (D_800D9E18 != 0) {
        func_80002E38(D_8017A2C0);
        D_800D9E18 = 0;
    }
    D_800D9D9C = 0;
}
