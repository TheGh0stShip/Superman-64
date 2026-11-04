extern float D_800DFEB0;
extern float D_800DFEB4;

float func_800D1860(int exponent) {
    float result = 1.0f;
    float base;

    if (exponent >= 0) {
        base = D_800DFEB0;
    } else {
        base = D_800DFEB4;
        exponent = -exponent;
    }

    while (exponent != 0) {
        if (exponent & 1) {
            result *= base;
        }
        base *= base;
        exponent >>= 1;
    }
    return result;
}
