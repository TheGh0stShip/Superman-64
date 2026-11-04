extern short D_8017A320;
extern short D_800E8B20[];
extern void *D_800D6104;

extern void func_800C45F0(void *arg0, int arg1);
extern int func_800D0210(void *arg0);
extern void func_800C78C0(void *arg0, int arg1);
extern void func_800D0000(void *arg0, unsigned char arg1);
extern void func_800CD3D0(void *arg0, short arg1);

void func_800029A0(int index, unsigned char flags, int arg2, short arg3,
                   unsigned char arg4) {
    if (D_8017A320 == 0 && D_800E8B20[index] != -1) {
        func_800C45F0(D_800D6104, D_800E8B20[index]);
        if (func_800D0210(D_800D6104) == 1) {
            if (flags & 1) {
                func_800C78C0(D_800D6104, arg2);
            }
            if (flags & 4) {
                func_800D0000(D_800D6104, arg4);
            }
            if (flags & 2) {
                func_800CD3D0(D_800D6104, arg3);
            }
        }
    }
}
