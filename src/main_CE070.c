typedef unsigned char u8;
typedef unsigned int u32;

void *func_800CD470(void *destination, const void *source, u32 count) {
    u8 *output = destination;
    const u8 *input = source;

    while (count != 0) {
        *output++ = *input++;
        count--;
    }
    return destination;
}

u32 func_800CD49C(const char *string) {
    const char *current = string;

    while (*current != '\0') {
        current++;
    }
    return current - string;
}

char *func_800CD4C4(const char *string, int character) {
    u8 target = character;

    while (*string != target) {
        if (*string == '\0') {
            return 0;
        }
        string++;
    }
    return (char *)string;
}
