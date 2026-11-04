typedef struct {
    char pad00[0xE];
    short enabled;
} RuntimeFlag;

typedef struct {
    char pad00[0x18];
    RuntimeFlag *flag;
} RuntimeLink;

typedef struct {
    char pad00[0x6C];
    float first_value;
    char pad70[0x14];
    RuntimeLink *first_link;
    char pad88[8];
    float second_value;
    char pad94[0x14];
    RuntimeLink *second_link;
    char padAC[8];
    float third_value;
    char padB8[0x14];
    RuntimeLink *third_link;
} RuntimeRecord;

extern signed char D_8015E84C;
extern RuntimeRecord *D_800D838C[];
extern float D_800DEC44;
extern float D_800DEC48;
extern float D_800DEC4C;
extern float D_800DEC50;
extern float D_800DEC54;
extern float D_800DEC58;
extern float D_800D65F4;

void func_8008FB10(void) {
    RuntimeRecord *record = D_800D838C[D_8015E84C];
    if (record->first_value > D_800DEC44) {
        D_800D65F4 = D_800DEC48;
        record->first_link->flag->enabled = 1;
    }
}

void func_8008FB70(void) {
    RuntimeRecord *record = D_800D838C[D_8015E84C];
    if (record->second_value > D_800DEC4C) {
        D_800D65F4 = D_800DEC50;
        record->second_link->flag->enabled = 1;
    }
}

void func_8008FBD0(void) {
    RuntimeRecord *record = D_800D838C[D_8015E84C];
    if (record->third_value > D_800DEC54) {
        D_800D65F4 = D_800DEC58;
        record->third_link->flag->enabled = 1;
    }
}
