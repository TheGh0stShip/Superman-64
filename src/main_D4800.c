typedef signed int s32;
typedef float f32;

typedef struct {
    s32 values[4][4];
} Matrix;

extern void func_800D3A40(f32 matrix[4][4], f32 first, f32 second,
                          f32 third, f32 fourth);
extern void func_800C4340(f32 source[4][4], Matrix *destination);

void func_800D3C00(Matrix *matrix, f32 first, f32 second, f32 third,
                   f32 fourth) {
    f32 temporary[4][4];

    func_800D3A40(temporary, first, second, third, fourth);
    func_800C4340(temporary, matrix);
}
