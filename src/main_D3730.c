typedef signed int s32;

typedef struct {
    s32 quotient;
    s32 remainder;
} DivisionResult;

DivisionResult func_800D2B30(s32 dividend, s32 divisor) {
    DivisionResult result;

    result.quotient = dividend / divisor;
    result.remainder = dividend - divisor * result.quotient;
    if (result.quotient < 0 && result.remainder > 0) {
        result.quotient++;
        result.remainder -= divisor;
    }
    return result;
}
