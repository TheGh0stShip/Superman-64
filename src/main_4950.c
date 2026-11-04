typedef struct {
    unsigned char data[0x68];
} RuntimeRecord;

extern RuntimeRecord D_800E8C28[];
extern void *D_800E8DC8[];
extern int D_800E8DD8[];

extern void func_800C47B0(RuntimeRecord *record);
extern int func_800C4610(RuntimeRecord *record);

void func_80003D50(int index) {
    if (D_800E8DC8[index] != 0) {
        func_800C47B0(&D_800E8C28[index]);
        D_800E8DD8[index] = 1;
    }
}

void func_80003DC4(int index) {
    if (D_800E8DC8[index] != 0) {
        if (func_800C4610(&D_800E8C28[index]) != 4) {
            D_800E8DD8[index] = 0;
        }
    }
}
