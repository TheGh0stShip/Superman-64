typedef struct MotionRecord {
    char pad_00[0x48];
    float value_48;
    char pad_4C[0x0C];
    float base_58;
    char pad_5C[0x08];
    float offset_64;
    char pad_68[0x04];
} MotionRecord;

extern MotionRecord D_8015EB1C[];

extern float func_8001119C(float value);
extern float func_8005A4A4(float value);
extern float func_8005AAB0(float limit, float value);

void func_80017310(float delta, float limit, int index) {
    float value;

    value = D_8015EB1C[index].offset_64 + delta;
    value -= D_8015EB1C[index].base_58;
    value = func_8001119C(value);
    if (limit <= func_8005A4A4(value)) {
        D_8015EB1C[index].value_48 =
            D_8015EB1C[index].base_58 + func_8005AAB0(limit, value);
    } else {
        D_8015EB1C[index].value_48 = D_8015EB1C[index].base_58 + value;
    }
}
