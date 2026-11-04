typedef unsigned int u32;
typedef char *va_list;

#define va_start(list, last) (list = ((va_list)&last + sizeof(last)))

extern void *func_800CD470(void *, const void *, u32);
extern int func_800CCBC0(void *(*)(void *, const char *, u32), void *,
                        const char *, va_list);

void *func_800CC4D0(void *destination, const char *source, u32 count) {
    return (char *)func_800CD470(destination, source, count) + count;
}

int func_800CC4F4(char *destination, const char *format, ...) {
    int result;
    va_list arguments;

    va_start(arguments, format);
    result = func_800CCBC0(func_800CC4D0, destination, format, arguments);
    if (result >= 0) {
        destination[result] = 0;
    }
    return result;
}
