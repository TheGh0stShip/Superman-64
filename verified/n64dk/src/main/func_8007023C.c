typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

typedef struct Actor {
    u8 pad00[0xD4];
    f32 velocityX;
    u8 padD8[4];
    f32 velocityZ;
    f32 positionX;
    u8 padE4[4];
    f32 positionZ;
    u8 padEC[0x1E0];
} Actor;

extern Actor *D_8015FB9C;

void func_8007023C(s32 arg0) {
    D_8015FB9C[arg0].positionX += D_8015FB9C[arg0].velocityX;
    D_8015FB9C[arg0].positionZ += D_8015FB9C[arg0].velocityZ;
    D_8015FB9C[arg0].velocityX = 0.0f;
    D_8015FB9C[arg0].velocityZ = 0.0f;
}
