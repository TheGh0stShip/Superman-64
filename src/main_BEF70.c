typedef int Matrix[4][4];

extern void func_800C4440(float matrix[4][4]);
extern void func_800C4340(float source[4][4], Matrix *destination);

void func_800BE370(float matrix[4][4], float x, float y, float z) {
    func_800C4440(matrix);
    matrix[0][0] = x;
    matrix[1][1] = y;
    matrix[2][2] = z;
    matrix[3][3] = 1.0f;
}

void func_800BE3C4(Matrix *matrix, float x, float y, float z) {
    float temporary[4][4];

    func_800BE370(temporary, x, y, z);
    func_800C4340(temporary, matrix);
}
