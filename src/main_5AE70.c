typedef struct {
    float x;
    float y;
    float z;
} Vec3f;

float func_8005A270(Vec3f first, Vec3f second) {
    return first.x * second.x + first.y * second.y + first.z * second.z;
}

void func_8005A2B4(float x, float y, float z, Vec3f *result) {
    result->x = x;
    result->y = y;
    result->z = z;
}

void func_8005A2D0(Vec3f *source, Vec3f *destination) {
    destination->x = source->x;
    destination->y = source->y;
    destination->z = source->z;
}
