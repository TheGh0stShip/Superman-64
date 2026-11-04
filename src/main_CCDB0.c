typedef unsigned char u8;

typedef struct {
    u8 data[0x40];
} Transform;

extern void func_800C44F8(Transform *destination, Transform *source);
extern void func_800CC270(Transform *transform, int, int, int, int, int, int);
extern void func_800CC310(Transform *left, Transform *right,
                          Transform *result);
extern void func_800C4340(Transform *transform, void *destination);

void func_800CC1B0(Transform *transform, int arg1, int arg2, int arg3,
                   int arg4, int arg5, int arg6) {
    Transform copy;

    func_800C44F8(&copy, transform);
    func_800CC270(&copy, arg1, arg2, arg3, arg4, arg5, arg6);
}

void func_800CC210(Transform *left, Transform *right, void *destination) {
    Transform leftCopy;
    Transform rightCopy;
    Transform result;

    func_800C44F8(&leftCopy, left);
    func_800C44F8(&rightCopy, right);
    func_800CC310(&leftCopy, &rightCopy, &result);
    func_800C4340(&result, destination);
}
