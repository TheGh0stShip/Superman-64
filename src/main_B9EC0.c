typedef struct {
    char pad00[0x78];
    int value78;
} RuntimeObject;

typedef struct {
    char pad00[0x9C];
    void *value9C;
} RuntimeData;

extern short D_80144334;
extern short D_801442E6;
extern short D_801442E8;
extern short D_8017AB9C;
extern short D_8017A2C8;
extern RuntimeData D_8017A028[];
extern void *D_8015FF80;

extern void func_800B8FF0(int arg0);
extern void func_800B9068(void);
extern void func_800B6A64(int arg0);
extern void func_8000277C(int, void *, int, int, int);
extern void func_8002C044(int, int, int, int, void *);
extern void func_8002BC48(int, int, int, void *);
extern void func_800B9200(void);
extern void func_800B74D4(void);

void func_800B92C0(void *arg0) {
    func_800B8FF0(1);
    func_800B9068();
}

void func_800B92EC(void) {
    if (D_80144334 == 2) {
        func_800B6A64(7);
        func_8000277C(0x27, D_8017A028[0].value9C, D_8017A2C8, 0x40, 0);
        func_8002C044(0x86, 0, 0xC, 0x52, D_8015FF80);
        func_8002BC48(0x1B, 0x54, 0x53, D_8015FF80);
        func_8002BC48(0x1A, 0x54, 0x53, D_8015FF80);
    }
}

void func_800B9394(RuntimeObject *object) {
    D_8017AB9C = 0;
    if (object->value78 != D_801442E6) {
        func_800B9200();
    } else {
        D_801442E8 = object->value78 + 1;
        func_800B9068();
        func_800B74D4();
    }
}
