typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern u8 D_800DB340;
extern s32 func_800D3D00(void);
extern u32 func_800C30E0(void *address);

#define AUDIO_DRAM_ADDRESS (*(volatile u32 *)0xA4500000)
#define AUDIO_LENGTH (*(volatile u32 *)0xA4500004)

s32 func_800D3C50(void *buffer, u32 size) {
    char *adjusted = buffer;

    if (D_800DB340 != 0) {
        adjusted -= 0x2000;
    }

    if ((((u32)buffer + size) & 0x1FFF) == 0) {
        D_800DB340 = 1;
    } else {
        D_800DB340 = 0;
    }

    if (func_800D3D00()) {
        return -1;
    }

    AUDIO_DRAM_ADDRESS = func_800C30E0(adjusted);
    AUDIO_LENGTH = size;
    return 0;
}
