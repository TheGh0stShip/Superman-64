typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u16 unkC;
    u16 unkE;
    u32 unk10;
} Struct800CC4B0;

void func_800CC4B0(Struct800CC4B0 *arg0, u32 arg1, u32 arg2, u32 arg3) {
    arg0->unk0 = 0;
    arg0->unk4 = arg1;
    arg0->unk8 = arg2;
    arg0->unkC = 0;
    arg0->unkE = 0;
    arg0->unk10 = arg3;
}
