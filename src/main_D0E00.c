typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u8 pad[0x2C];
    u32 value;
} ValueAt2C;

u32 func_800D0200(ValueAt2C *arg) {
    return arg->value;
}
