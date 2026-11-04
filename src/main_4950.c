typedef struct {
    unsigned char data[0x68];
} RuntimeRecord;

extern RuntimeRecord D_800E8C28[];
extern void *D_800E8DC8[];
extern int D_800E8DD8[];
extern unsigned int D_800E8DE8[];
extern unsigned int D_800E8DF8[];
extern short D_8017A320;
extern void *D_800D6228;
extern void *D_800E8C20;

extern void func_800C47B0(RuntimeRecord *record);
extern int func_800C4610(RuntimeRecord *record);
extern void func_800C4ACC(void *arg0, RuntimeRecord *record, int index);

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

void func_80003E40(int index, unsigned int state) {
    if (D_8017A320 != 0 || D_800D6228 != 0) {
        state = 0;
    }
    if (D_800E8DC8[index] != 0) {
        if (state >= 0x51) {
            state = 0x50;
        }
        if (state & 0x08000000) {
            state = 0;
        }
        D_800E8DE8[index] = state;
    }
}

void func_80003EB4(void) {
    unsigned int index;
    unsigned int state;

    for (index = 0; index < 4; index++) {
        if (D_800E8DC8[index] != 0) {
            state = D_800E8DE8[index];
            if (state >= 0x47) {
                if (D_800E8DD8[index] == 0) {
                    func_80003D50(index);
                }
            } else if (state < 6) {
                if (state == 1) {
                    func_800C4ACC(D_800E8C20, &D_800E8C28[index], index);
                    func_80003DC4(index);
                    D_800E8DE8[index] = 0;
                } else if (D_800E8DD8[index] != 0) {
                    func_80003DC4(index);
                }
            } else if (D_800E8DF8[index] >= 0x100) {
                D_800E8DF8[index] -= 0x100;
                if (D_800E8DD8[index] == 0) {
                    func_80003D50(index);
                }
            } else {
                D_800E8DF8[index] += ((state * state * state) >> 9) + 4;
                if (D_800E8DD8[index] != 0) {
                    func_80003DC4(index);
                }
            }
        }
    }
}
