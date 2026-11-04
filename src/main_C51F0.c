typedef signed short s16;
typedef unsigned char u8;

typedef struct {
    u8 pad[0x3C];
    int value;
} ValueAt3C;

void func_800C45F0(ValueAt3C *arg0, s16 arg1) {
    arg0->value = arg1;
}
