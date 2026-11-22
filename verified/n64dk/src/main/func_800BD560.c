typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

typedef struct Bounds {
    s16 enabled;
    u8 pad02[2];
    f32 minX;
    f32 minY;
    f32 minZ;
    f32 maxX;
    f32 maxY;
    f32 maxZ;
} Bounds;

void func_800BD560(Bounds *arg0) {
    f32 temp;

    if (arg0->enabled == 1) {
        if (arg0->minX > arg0->maxX) {
            temp = arg0->minX;
            arg0->minX = arg0->maxX;
            arg0->maxX = temp;
        }
        if (arg0->minY > arg0->maxY) {
            temp = arg0->minY;
            arg0->minY = arg0->maxY;
            arg0->maxY = temp;
        }
        if (arg0->minZ > arg0->maxZ) {
            temp = arg0->minZ;
            arg0->minZ = arg0->maxZ;
            arg0->maxZ = temp;
        }
    }
}
