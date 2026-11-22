typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
typedef double f64;

f32 func_80010D0C(void *arg0, s32 arg1, s32 arg2) {
    f32 sp4;
    u32 sp0;

    sp0 = (arg1 * 4) + arg2;
    sp4 = (f32)((f64)(f32)*(s16 *)((s8 *)arg0 + sp0 * 2) +
                (f64)(f32)*(u16 *)((s8 *)arg0 + sp0 * 2 + 0x20) / 65536.0);
    return sp4;
}
