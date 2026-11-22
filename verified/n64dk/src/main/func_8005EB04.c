typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;

void func_80010488(f32 matrix[16], s32 index);
void func_80011EFC(f32 matrix[16], f32 *position);
extern f32 D_8013F634;
extern f32 D_8013F638;
extern f32 D_8013F63C;
extern f32 D_8015F9EC;
extern f32 D_8015F9F0;
extern f32 D_8015F9F4;

typedef struct {
    u8 pad0[0xE0];
    f32 x;
    f32 y;
    f32 z;
    u8 padEC[0x1E0];
} UnkObject;

extern UnkObject *D_8015FB9C;

void func_8005EB04(s32 arg0) {
    f32 sp18[16];

    func_80010488(&sp18, arg0);
    func_80011EFC(&sp18, &D_8015F9EC);
    D_8013F634 = D_8015FB9C[arg0].x + D_8015F9EC;
    D_8013F638 = D_8015FB9C[arg0].y + D_8015F9F0;
    D_8013F63C = D_8015FB9C[arg0].z + D_8015F9F4;
}
