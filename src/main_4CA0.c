typedef signed short s16;

extern int func_800CD49C(unsigned char *text);

unsigned int func_800040A0(unsigned char *text) {
    s16 index;
    unsigned int value;
    int multiplier;

    multiplier = 1;
    value = 0;
    index = func_800CD49C(text) - 1;

    while (index >= 0) {
        if (text[index] >= '0' && text[index] < ':') {
            value += multiplier * (text[index] - '0');
            multiplier *= 10;
        }
        index--;
    }
    return value;
}
