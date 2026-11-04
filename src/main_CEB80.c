typedef signed int s32;
typedef float f32;

typedef struct {
    s32 values[4][4];
} Matrix;

extern void func_800CDDD0(f32 matrix[4][4], f32 roll, f32 pitch, f32 yaw,
                          f32 scale, f32 x, f32 y, f32 z);
extern void func_800C4340(f32 source[4][4], Matrix *destination);

void func_800CDF80(Matrix *matrix, f32 roll, f32 pitch, f32 yaw,
                   f32 scale, f32 x, f32 y, f32 z) {
    f32 temporary[4][4];

    func_800CDDD0(temporary, roll, pitch, yaw, scale, x, y, z);
    func_800C4340(temporary, matrix);
}
