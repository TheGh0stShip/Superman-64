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

/* Provisional declarations recovered from machine code by n64dk. Evidence, not truth. */
struct Struct_func_80011EFC_arg0;
struct Struct_func_80011EFC_arg1;
struct Struct_func_80011EFC_arg0 {   /* provisional: 6 field(s) from 1 function(s) */
    /* 0x00 */ char unk_0[0x18];
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ char unk_1E[0x1A];
    /* 0x38 */ u16 unk_38;
    /* 0x3A */ u16 unk_3A;
    /* 0x3C */ u16 unk_3C;
};
struct Struct_func_80011EFC_arg1 {   /* provisional: 3 field(s) from 1 function(s) */
    /* 0x00 */ f32 unk_0;
    /* 0x04 */ f32 unk_4;
    /* 0x08 */ f32 unk_8;
};
void func_80011EFC(struct Struct_func_80011EFC_arg0 *, struct Struct_func_80011EFC_arg1 *);

void func_80011EFC(struct Struct_func_80011EFC_arg0 *arg0, struct Struct_func_80011EFC_arg1 *arg1) {
    arg1->unk_0 = ((f32) arg0->unk_38 / 65536.0f) + (f32) arg0->unk_18;
    arg1->unk_4 = ((f32) arg0->unk_3A / 65536.0f) + (f32) arg0->unk_1A;
    arg1->unk_8 = ((f32) arg0->unk_3C / 65536.0f) + (f32) arg0->unk_1C;
}
