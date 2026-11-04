typedef signed short s16;
typedef struct ALSynth ALSynth;

typedef struct {
    unsigned char pad00[0x16];
    s16 priority;
} ALVoice;

void func_800C2AB0(ALSynth *synth, ALVoice *voice, s16 priority) {
    (void)synth;
    voice->priority = priority;
}
