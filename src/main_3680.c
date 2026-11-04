extern short D_8017A320;
extern short D_800E8B20[];
extern void *D_800D6104;

extern void func_800C45F0(void *arg0, int arg1);
extern void func_800C3CB0(void *arg0, unsigned char arg1);
extern int func_800D0210(void *arg0);
extern void func_800BFE40(void *arg0);
extern int D_800D60FC;
extern int D_800D6100;
extern void *D_800D6108;
extern void *D_800D610C;
extern void *D_800E8B04;
extern void *D_800E8B08;
extern int D_800E8AF0;
extern int D_800E8BD0;
extern int D_800E8BE0;

extern void func_80002D64(void);
extern void func_80002DD8(void);
extern void func_800C2924(void *arg0, void *arg1);
extern int func_800011A0(int arg0, void *arg1, int arg2);
extern void func_800C01B4(void *arg0, int arg1);
extern void func_800C3008(void *arg0, void *arg1, int arg2);
extern void func_800C2CD8(void *arg0, void *arg1, int arg2);
extern void func_800CD430(void *arg0, void *arg1, void *arg2, int arg3);
extern void func_800C45B0(void *arg0, void *arg1);
extern void func_800BF030(void *arg0, void *arg1);
extern void func_800CD210(void *arg0, short arg1);
extern void func_800D1480(void *arg0);
extern void func_800C38B0(void *arg0);
extern int func_800D0200(void *arg0);

typedef struct {
    int unk0;
    int unk4;
    unsigned char unk8;
    unsigned char pad9[3];
    void *unkC;
    int unk10;
    int unk14;
    int unk18;
} LocalConfig;

void func_80002A80(int index, unsigned char value) {
    if (D_8017A320 == 0) {
        if (D_800E8B20[index] != -1) {
            func_800C45F0(D_800D6104, D_800E8B20[index]);
            func_800C3CB0(D_800D6104, value);
        }
    }
}

void func_80002AF0(int index) {
    if (D_8017A320 == 0) {
        if (D_800E8B20[index] != -1) {
            func_800C45F0(D_800D6104, D_800E8B20[index]);
            if (func_800D0210(D_800D6104) == 1) {
                func_800BFE40(D_800D6104);
            }
        }
    }
}

int func_80002B70(int index) {
    if (D_8017A320 != 0) {
        return 0;
    }
    if (D_800E8B20[index] != -1) {
        func_800C45F0(D_800D6104, D_800E8B20[index]);
        if (func_800D0210(D_800D6104) == 0) {
            return 0;
        }
        return 1;
    }
    return 0;
}

void func_80002BFC(int arg0, int arg1, int arg2) {
    LocalConfig config;
    int value;

    if (D_800D60FC != 0) {
        func_80002D64();
    }
    if (D_800D60FC == 0) {
        config.unk0 = 0x40;
        config.unk4 = 0x40;
        config.unk8 = 0x10;
        config.unkC = &D_800E8AF0;
        config.unk10 = 0;
        config.unk14 = 0;
        config.unk18 = 0;
        func_800C2924(D_800D6108, &config);
        func_800011A0(arg1, D_800E8B08, 0);
        func_800C01B4(D_800E8B08, arg2);
    }
    value = func_800011A0(arg0, D_800E8B04, 0);
    func_800C3008(D_800D610C, D_800E8B04, value);
    func_800C2CD8(D_800D610C, &D_800E8BD0, 0);
    func_800C2CD8(D_800D610C, &D_800E8BE0, -1);
    func_800CD430(D_800D6108, &D_800E8BD0, &D_800E8BE0, -1);
    func_800C45B0(D_800D6108, D_800D610C);
    func_800BF030(D_800D6108, ((void **)D_800E8B08)[1]);
    D_800D60FC = 1;
}

void func_80002D64(void) {
    func_80002DD8();
}

void func_80002D84(short arg0) {
    if (D_800D6100 == 0) {
        D_800D6100 = 1;
        func_800CD210(D_800D6108, arg0);
        func_800D1480(D_800D6108);
    }
}

void func_80002DD8(void) {
    if (D_800D6100 != 0) {
        D_800D6100 = 0;
        func_800C38B0(D_800D6108);
        while (func_800D0200(D_800D6108) != 0) {
        }
    }
}

void func_80002E38(short arg0) {
    if (D_800D6100 != 0) {
        func_800CD210(D_800D6108, arg0);
    }
}
