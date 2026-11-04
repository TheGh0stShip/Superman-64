typedef signed int s32;
typedef float f32;

typedef struct {
    s32 values[4][4];
} Matrix;

extern void func_800CECA0(f32 *x, f32 *y, f32 *z);
extern f32 func_800BE410(f32 angle);
extern f32 func_800CFC60(f32 angle);
extern void func_800C4440(f32 matrix[4][4]);
extern void func_800C4340(f32 source[4][4], Matrix *destination);

void func_800CE780(f32 matrix[4][4], f32 angle, f32 x, f32 y, f32 z) {
    static f32 degrees_to_radians = 3.1415926 / 180.0;
    f32 sine;
    f32 cosine;
    f32 xy;
    f32 yz;
    f32 zx;
    f32 t;

    func_800CECA0(&x, &y, &z);
    angle *= degrees_to_radians;
    sine = func_800BE410(angle);
    cosine = func_800CFC60(angle);
    t = 1 - cosine;
    xy = x * y * t;
    yz = y * z * t;
    zx = z * x * t;

    func_800C4440(matrix);

    t = x * x;
    matrix[0][0] = t + cosine * (1 - t);
    matrix[2][1] = yz - x * sine;
    matrix[1][2] = yz + x * sine;

    t = y * y;
    matrix[1][1] = t + cosine * (1 - t);
    matrix[2][0] = zx + y * sine;
    matrix[0][2] = zx - y * sine;

    t = z * z;
    matrix[2][2] = t + cosine * (1 - t);
    matrix[1][0] = xy - z * sine;
    matrix[0][1] = xy + z * sine;
}

void func_800CE914(Matrix *matrix, f32 angle, f32 x, f32 y, f32 z) {
    f32 temporary[4][4];

    func_800CE780(temporary, angle, x, y, z);
    func_800C4340(temporary, matrix);
}
