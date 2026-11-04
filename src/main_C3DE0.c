typedef signed int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    u32 instruction1;
    u32 instruction2;
    u32 instruction3;
    u32 instruction4;
} ExceptionVector;

extern ExceptionVector func_800BE5D0[];
extern u32 D_8000030C;
extern unsigned char D_8000031C[];
extern u32 D_80000300;

u64 osClockRate = 62500000;
s32 osViClock = 48681812;
u32 __osShutdown = 0;
u32 __OSGlobalIntMask = 0x003FFF01;
u32 __osFinalrom;

extern u32 func_800C38A0(void);
extern void func_800C3890(u32 status);
extern void func_800D0230(u32 control);
extern s32 func_800C3D80(u32 address, u32 *value);
extern s32 func_800D2E60(u32 address, u32 value);
extern void func_800C3160(void *address, s32 size);
extern void func_800CD540(void *address, s32 size);
extern void func_800D1710(void);
extern s32 func_800C3470(u32 address, u32 *value);
extern void func_800C3790(void *address, s32 size);

void func_800C31E0(void) {
    u32 pif_data;
    u32 clock = 0;

    __osFinalrom = 1;
    func_800C3890(func_800C38A0() | 0x20000000);
    func_800D0230(0x01000800);

    while (func_800C3D80(0x1FC007FC, &pif_data)) {
    }
    while (func_800D2E60(0x1FC007FC, pif_data | 8)) {
    }

    *(ExceptionVector *)0x80000000 = *func_800BE5D0;
    *(ExceptionVector *)0x80000080 = *func_800BE5D0;
    *(ExceptionVector *)0x80000100 = *func_800BE5D0;
    *(ExceptionVector *)0x80000180 = *func_800BE5D0;
    func_800C3160((void *)0x80000000, 0x190);
    func_800CD540((void *)0x80000000, 0x190);

    func_800D1710();
    func_800C3470(4, &clock);
    clock &= ~0xF;
    if (clock != 0) {
        osClockRate = clock;
    }
    osClockRate = osClockRate * 3 / 4;

    if (D_8000030C == 0) {
        func_800C3790(D_8000031C, 0x40);
    }

    if (D_80000300 == 0) {
        osViClock = 0x02F5B2D2;
    } else if (D_80000300 == 2) {
        osViClock = 0x02E6025C;
    } else {
        osViClock = 0x02E6D354;
    }
}
