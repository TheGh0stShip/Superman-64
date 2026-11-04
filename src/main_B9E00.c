typedef struct {
    char pad00[0x24];
    float value;
    char pad28[0x2A4];
} RuntimeRecord;

extern int D_800D9DBC;
extern int D_801442DC;
extern int D_8015FB88;
extern RuntimeRecord *D_8015FB9C;

extern void func_800B8FF0(int arg0);
extern void func_800B9068(void);
extern void func_800B6A50(void);

void func_800B9200(void) {
    func_800B8FF0(4);
    func_800B9068();
    if (D_800D9DBC != 3) {
        func_800B6A50();
        D_8015FB9C[D_8015FB88].value = -10.0f;
    } else {
        D_801442DC = 0;
    }
}

void func_800B9294(void *arg0) {
    func_800B8FF0(3);
    func_800B9068();
}
