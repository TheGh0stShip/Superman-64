typedef struct {
    int unk0;
    int id;
    unsigned int flags;
    unsigned char padC[0x1C];
} RuntimeEntry;

typedef struct {
    unsigned char data[0x40];
} Transform;

extern void func_800CE914(Transform *destination, float angle, float x,
                          float y, float z);
extern void func_800CC210(Transform *left, Transform *right,
                          Transform *destination);
extern void func_800CC1B0(Transform *transform, float arg1, float arg2,
                          float arg3, float *x, float *y, float *z);
extern double D_800DF428;
extern double D_800DF430;

int func_800B7300(RuntimeEntry *entry, unsigned int mask,
                  unsigned int expected) {
    while (entry->id != -0x40) {
        if (entry->id == 0x206 && (entry->flags & mask) == expected) {
            return 1;
        }
        entry++;
    }
    return 0;
}

int func_800B7358(RuntimeEntry *entry) {
    return func_800B7300(entry, 0x8000, 0x8000);
}

int func_800B7384(RuntimeEntry *entry) {
    return func_800B7300(entry, 0xFF000000, 0x01000000);
}

void func_800B73B0(float *position, float firstAngle, float secondAngle) {
    Transform result;
    Transform first;
    Transform second;
    Transform unused;

    func_800CE914(&first, firstAngle * D_800DF428,
                  0.0f, 1.0f, 0.0f);
    func_800CE914(&second, secondAngle * D_800DF430,
                  1.0f, 0.0f, 0.0f);
    func_800CC210(&first, &second, &result);
    func_800CC1B0(&result, 0.0f, 0.0f, 1.0f,
                  position, position + 1, position + 2);
}
