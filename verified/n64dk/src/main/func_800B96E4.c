typedef unsigned char u8;
typedef signed int s32;

typedef struct {
    u8 pad0[0x70];
    s32 state;
} UnkObject;

extern s32 D_801442D8;
extern s32 D_801442DC;

void func_800B9200(void);
void func_800B9294(UnkObject *arg0);
void func_800B92C0(UnkObject *arg0);
void func_800B9394(UnkObject *arg0);

void func_800B96E4(UnkObject *arg0, s32 arg1) {
    if (D_801442DC > D_801442D8) {
        func_800B9200();
        return;
    }
    if (arg1 < 8) {
        if ((arg0->state & 0xFF) == 3) {
            func_800B9394(arg0);
            return;
        }
        if (arg1 == 0) {
            func_800B9294(arg0);
            return;
        }
        func_800B92C0(arg0);
    }
}
