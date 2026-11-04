typedef unsigned short u16;
typedef float f32;
typedef signed int s32;

typedef struct {
    s32 values[4][4];
} Matrix;

extern void func_800C38E0(f32 matrix[4][4], u16 *normalization, f32 fieldOfView,
                          f32 aspect, f32 near, f32 far, f32 scale);
extern void func_800C4340(f32 source[4][4], Matrix *destination);

void func_800C3B10(Matrix *matrix, u16 *normalization, f32 fieldOfView,
                   f32 aspect, f32 near, f32 far, f32 scale) {
    f32 temporary[4][4];

    func_800C38E0(temporary, normalization, fieldOfView, aspect, near, far,
                  scale);
    func_800C4340(temporary, matrix);
}
