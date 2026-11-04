typedef signed long long s64;

typedef struct {
    s64 quotient;
    s64 remainder;
} LongDivisionResult;

extern s64 func_800C35DC(s64 dividend, s64 divisor);
extern s64 func_800C3638(s64 first, s64 second);

LongDivisionResult func_800D2A30(s64 dividend, s64 divisor) {
    LongDivisionResult result;

    result.quotient = func_800C35DC(dividend, divisor);
    result.remainder = dividend - func_800C3638(divisor, result.quotient);
    if (result.quotient < 0 && result.remainder > 0) {
        result.quotient++;
        result.remainder -= divisor;
    }
    return result;
}
