void __ull_divremi(unsigned long long *quotient, unsigned long long *remainder,
                   unsigned long long dividend, unsigned short divisor)
{
    *quotient = dividend / divisor;
    *remainder = dividend % divisor;
}
