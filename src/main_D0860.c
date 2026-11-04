extern double D_800DFE50[];
extern double D_800DFE78;
extern double D_800DFE80;
extern double D_800DFE88;
extern float D_800DFE90;
extern float D_800DFEA0;

float func_800CFC60(float x) {
    float absolute_x;
    double dx;
    double x_squared;
    double polynomial;
    double rounded;
    int n;
    double result;
    int bits;
    int exponent;

    bits = *(int *)&x;
    exponent = (bits >> 22) & 0x1FF;

    if (exponent < 0x136) {
        absolute_x = (x > 0.0f) ? x : -x;
        dx = absolute_x;
        rounded = dx * D_800DFE78 + 0.5;
        n = (int)((rounded >= 0.0) ? (rounded + 0.5) : (rounded - 0.5));
        rounded = n;
        rounded -= 0.5;
        dx = dx - rounded * D_800DFE80;
        dx = dx - rounded * D_800DFE88;
        x_squared = dx * dx;
        polynomial = ((D_800DFE50[4] * x_squared + D_800DFE50[3]) * x_squared +
                      D_800DFE50[2]) * x_squared + D_800DFE50[1];
        result = dx + (dx * x_squared) * polynomial;

        if ((n & 1) == 0) {
            return (float)result;
        }
        return -(float)result;
    }

    if (x != x) {
        return D_800DFEA0;
    }
    return D_800DFE90;
}
