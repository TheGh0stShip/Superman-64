typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    s32 values[4][4];
} Matrix;

#define FIXED_TO_FLOAT(value) ((f32)(value) * (1.0f / (f32)0x10000))

#define FLOAT_TO_FIXED(value) ((s32)((value) * (f32)0x10000))

void func_800C4340(f32 source[4][4], Matrix *destination) {
    s32 row;
    s32 column;
    s32 first;
    s32 second;
    s32 *integer;
    s32 *fraction;

    integer = &destination->values[0][0];
    fraction = &destination->values[2][0];
    for (row = 0; row < 4; row++) {
        for (column = 0; column < 2; column++) {
            first = FLOAT_TO_FIXED(source[row][column * 2]);
            second = FLOAT_TO_FIXED(source[row][column * 2 + 1]);
            *integer++ = (first & 0xFFFF0000) | ((second >> 16) & 0xFFFF);
            *fraction++ = ((first << 16) & 0xFFFF0000) |
                          (second & 0xFFFF);
        }
    }
}

void func_800C4440(f32 matrix[4][4]) {
    s32 row;
    s32 column;

    for (row = 0; row < 4; row++) {
        for (column = 0; column < 4; column++) {
            if (row == column) {
                matrix[row][column] = 1.0f;
            } else {
                matrix[row][column] = 0.0f;
            }
        }
    }
}

void func_800C44C8(Matrix *matrix) {
    f32 temporary[4][4];

    func_800C4440(temporary);
    func_800C4340(temporary, matrix);
}

void func_800C44F8(f32 destination[4][4], Matrix *source) {
    s32 row;
    s32 column;
    u32 first;
    u32 second;
    u32 *integer;
    u32 *fraction;
    s32 signedFirst;
    s32 signedSecond;

    integer = (u32 *)&source->values[0][0];
    fraction = (u32 *)&source->values[2][0];
    for (row = 0; row < 4; row++) {
        for (column = 0; column < 2; column++) {
            first = (*integer & 0xFFFF0000) | ((*fraction >> 16) & 0xFFFF);
            second = ((*integer++ << 16) & 0xFFFF0000) |
                     (*fraction++ & 0xFFFF);
            signedFirst = *(s32 *)&first;
            signedSecond = *(s32 *)&second;
            destination[row][column * 2] = FIXED_TO_FLOAT(signedFirst);
            destination[row][column * 2 + 1] = FIXED_TO_FLOAT(signedSecond);
        }
    }
}
