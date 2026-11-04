typedef float f32;

extern void func_800CECA0(f32 *x, f32 *y, f32 *z);
extern f32 func_800BE410(f32 angle);
extern f32 func_800CFC60(f32 angle);
extern f32 func_800CC1A0(f32 value);
extern void func_800C4440(f32 matrix[4][4]);

void func_800D3A40(f32 matrix[4][4], f32 angle, f32 x, f32 y, f32 z) {
    static f32 degrees_to_radians = 3.1415926 / 180.0;
    f32 sine;
    f32 cosine;
    f32 horizontal;
    f32 horizontal_inverse;

    func_800CECA0(&x, &y, &z);

    angle *= degrees_to_radians;
    sine = func_800BE410(angle);
    cosine = func_800CFC60(angle);
    horizontal = func_800CC1A0(x * x + z * z);

    func_800C4440(matrix);

    if (horizontal != 0) {
        horizontal_inverse = 1 / horizontal;

        matrix[0][0] = (-z * cosine - sine * y * x) * horizontal_inverse;
        matrix[1][0] = (z * sine - cosine * y * x) * horizontal_inverse;
        matrix[2][0] = -x;
        matrix[3][0] = 0;

        matrix[0][1] = sine * horizontal;
        matrix[1][1] = cosine * horizontal;
        matrix[2][1] = -y;
        matrix[3][1] = 0;

        matrix[0][2] = (cosine * x - sine * y * z) * horizontal_inverse;
        matrix[1][2] = (-sine * x - cosine * y * z) * horizontal_inverse;
        matrix[2][2] = -z;
        matrix[3][2] = 0;

        matrix[0][3] = 0;
        matrix[1][3] = 0;
        matrix[2][3] = 0;
        matrix[3][3] = 1;
    }
}
