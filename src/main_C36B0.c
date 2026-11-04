typedef signed short s16;
typedef unsigned int u32;

typedef struct {
    unsigned char pad00[8];
    u32 value08;
    u32 value0C;
    unsigned char pad10[10];
    s16 value1A;
} ALSeq;

typedef struct {
    u32 value00;
    u32 value04;
    unsigned char pad08[4];
    s16 value0C;
    unsigned char pad0E[8];
    s16 value16;
} ALSeqMarker;

void func_800C2AC0(ALSeq *sequence, ALSeqMarker *marker) {
    marker->value00 = sequence->value08;
    marker->value0C = sequence->value1A;
    marker->value04 = sequence->value0C;
}

void func_800C2ADC(ALSeq *sequence, ALSeqMarker *marker) {
    sequence->value08 = marker->value00;
    sequence->value1A = marker->value0C;
    sequence->value0C = marker->value04;
}

u32 func_800C2AF8(ALSeq *sequence) {
    return sequence->value0C;
}
