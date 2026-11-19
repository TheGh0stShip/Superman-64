long long __ll_mod(long long a0, long long a1)
{
    long long tmp = a0 % a1;

    if ((tmp < 0 && a1 > 0) || (tmp > 0 && a1 < 0))
        tmp += a1;
    return tmp;
}
