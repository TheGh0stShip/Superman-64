typedef struct {
    unsigned char pad00[0x44];
    int value44;
} RuntimeScale;

extern double D_800DFC10;

void func_800C7EC0(void) {
}

int func_800C7EC8(RuntimeScale *scale, int value) {
    float rounded;

    rounded = (float)((double)((float)value * (float)scale->value44) / D_800DFC10 + 0.5);

    return (int)rounded & ~15;
}
