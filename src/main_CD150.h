typedef unsigned int size_t;
typedef char *va_list;
typedef double ldouble;
typedef struct {
    long quot;
    long rem;
} ldiv_t;
typedef struct {
    long long quot;
    long long rem;
} lldiv_t;

#define NULL 0
#ifdef NON_MATCHING
#define va_arg(list, mode) \
    (*(mode *)((list) += ((sizeof(mode) + 3) & ~3), \
              (list) - ((sizeof(mode) + 3) & ~3)))
#else
#define _FP 1
#define _VA_FP_SAVE_AREA 0x10
#define _VA_ALIGN(p, a) \
    (((unsigned int)(((char *)(p)) + ((a) > 4 ? (a) : 4) - 1)) & \
     -((a) > 4 ? (a) : 4))
#define __va_stack_arg(list, mode) \
    (((list) = (char *)_VA_ALIGN(list, __builtin_alignof(mode)) + \
               _VA_ALIGN(sizeof(mode), 4)), \
     (((char *)list) - (_VA_ALIGN(sizeof(mode), 4) - sizeof(mode))))
#define __va_double_arg(list, mode) \
    (((long)list & 1) \
         ? (list = (char *)((long)list + 7), \
            (char *)((long)list - 6 - _VA_FP_SAVE_AREA)) \
         : (((long)list & 2) \
                ? (list = (char *)((long)list + 10), \
                   (char *)((long)list - 24 - _VA_FP_SAVE_AREA)) \
                : __va_stack_arg(list, mode)))
#define va_arg(list, mode) \
    ((mode *)(((__builtin_classof(mode) == _FP && \
                __builtin_alignof(mode) == sizeof(double)) \
                   ? __va_double_arg(list, mode) \
                   : __va_stack_arg(list, mode))))[-1]
#endif

typedef struct {
    union {
        long long ll;
        ldouble ld;
    } v;
    unsigned char *s;
    int n0;
    int nz0;
    int n1;
    int nz1;
    int n2;
    int nz2;
    int prec;
    int width;
    size_t nchar;
    unsigned int flags;
    char qual;
} PrintState;

#define FLAGS_SPACE 1
#define FLAGS_PLUS 2
#define FLAGS_MINUS 4
#define FLAGS_HASH 8
#define FLAGS_ZERO 16

extern char *func_800CD4C4(const char *text, int character);
extern size_t func_800CD49C(const char *text);
extern void func_800D2BC0(PrintState *state, char code);
extern void func_800D24E0(PrintState *state, char code);
extern ldiv_t func_800D2B30(long numerator, long denominator);
extern lldiv_t func_800D2A30(long long numerator, long long denominator);
extern void *func_800CD470(void *destination, const void *source, size_t count);
