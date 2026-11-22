typedef unsigned char u8;
typedef signed int s32;

extern u8 D_001A3180[];
void func_800011A0(void *source, void *destination, s32 mode);

void func_8001C2B8(void) {
    func_800011A0(D_001A3180, 0x801F4000, 0);
}
