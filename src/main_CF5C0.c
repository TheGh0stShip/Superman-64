typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern s32 D_800DA0B8;

#define AUDIO_CONTROL (*(volatile u32 *)0xA4500008)
#define AUDIO_DAC_RATE (*(volatile u32 *)0xA4500010)
#define AUDIO_BIT_RATE (*(volatile u32 *)0xA4500014)

s32 func_800CE9C0(u32 frequency) {
    register u32 dac_rate;
    register u8 bit_rate;
    register float rate;

    rate = D_800DA0B8 / (float)frequency + 0.5f;
    dac_rate = rate;
    if (dac_rate < 132) {
        return -1;
    }

    bit_rate = dac_rate / 66;
    if (bit_rate > 16) {
        bit_rate = 16;
    }

    AUDIO_DAC_RATE = dac_rate - 1;
    AUDIO_BIT_RATE = bit_rate - 1;
    AUDIO_CONTROL = 1;
    return D_800DA0B8 / (s32)dac_rate;
}
