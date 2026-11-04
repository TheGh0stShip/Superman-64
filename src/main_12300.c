typedef struct {
    char pad00[0xAC];
    float scale;
    char padB0[0x30];
    float x;
    float y;
    float z;
    char padEC[0x10];
    float angle0;
    float angle1;
    char pad104[0x1C8];
} RuntimeObject;

extern RuntimeObject *D_8015FB9C;

float func_80011E50(float angle0, float angle1, float z, float x);

float func_80011700(int first, int second) {
    float result;
    float scale;

    if ((double)D_8015FB9C[first].scale < 50.0) {
        scale = 50.0f;
    } else {
        scale = D_8015FB9C[first].scale;
    }

    result = func_80011E50(D_8015FB9C[first].angle1,
                           D_8015FB9C[first].angle0,
                           D_8015FB9C[second].z - D_8015FB9C[first].z,
                           D_8015FB9C[second].x - D_8015FB9C[first].x) /
             scale;
    return result;
}
