typedef float f32;

extern f32 func_800CC1A0(f32 value);

void func_800CECA0(f32 *x, f32 *y, f32 *z) {
    f32 length_inverse;

    length_inverse = 1.0f / func_800CC1A0((*x * *x) + (*y * *y) + (*z * *z));
    *x *= length_inverse;
    *y *= length_inverse;
    *z *= length_inverse;
}
