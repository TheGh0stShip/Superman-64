void func_800CED40(unsigned char *source, unsigned char *destination, int size) {
    unsigned char *input = source;
    unsigned char *output = destination;
    int i;

    for (i = 0; i < size; i++) {
        *output++ = *input++;
    }
}
