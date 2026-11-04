typedef struct MotionAngleRecord {
    char pad_00[0x44];
    float value_44;
    char pad_48[0x04];
    float base_4C;
    char pad_50[0x1C];
} MotionAngleRecord;

extern MotionAngleRecord D_8015EB1C[];
extern double D_800DBEE0;

extern float func_8001119C(float value);

void func_80017790(int index) {
    float value;
    float scaled;

    value = func_8001119C(D_8015EB1C[index].value_44 -
                          D_8015EB1C[index].base_4C);
    scaled = value * D_800DBEE0;
    D_8015EB1C[index].value_44 =
        func_8001119C(D_8015EB1C[index].base_4C + scaled);
}
