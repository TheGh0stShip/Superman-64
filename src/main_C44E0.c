typedef unsigned short u16;

extern void func_800C4440(float matrix[4][4]);
extern float func_800CFC60(float value);
extern float func_800BE410(float value);
extern const double D_800DFBE0;

void func_800C38E0(float matrix[4][4], u16 *normalization, float field_of_view,
                   float aspect, float near, float far, float scale) {
    float cotangent;
    int row;
    int column;

    func_800C4440(matrix);

    field_of_view *= D_800DFBE0;
    cotangent = func_800CFC60(field_of_view / 2) /
                func_800BE410(field_of_view / 2);

    matrix[0][0] = cotangent / aspect;
    matrix[1][1] = cotangent;
    matrix[2][2] = (near + far) / (near - far);
    matrix[2][3] = -1;
    matrix[3][2] = (2 * near * far) / (near - far);
    matrix[3][3] = 0;

    for (row = 0; row < 4; row++) {
        for (column = 0; column < 4; column++) {
            matrix[row][column] *= scale;
        }
    }

    if (normalization != (u16 *)0) {
        if (near + far <= 2.0) {
            *normalization = (u16)0xFFFF;
        } else {
            *normalization = (u16)((2.0 * 65536.0) / (near + far));
            if (*normalization <= 0) {
                *normalization = (u16)0x0001;
            }
        }
    }
}
