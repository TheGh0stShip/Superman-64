typedef signed int s32;
typedef float f32;

s32 guRandom(void);

f32 func_8008F7AC(f32 arg0, f32 arg1) {
    f32 sp1C;

    sp1C = ((f32)(guRandom() % 100) * (arg0 * arg1)) / 100.0f;
    sp1C -= arg1 / 2.0f;
    return arg0 + sp1C;
}
