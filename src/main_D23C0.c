typedef struct {
    float elements[4][4];
} Transform;

typedef struct {
    unsigned char header[0x10];
    Transform transform;
} TransformStorage;

extern void func_800C4440(Transform *transform);
extern void func_800C4340(Transform *transform, void *destination);

void func_800D17C0(Transform *transform, float x, float y, float z) {
    func_800C4440(transform);
    transform->elements[3][0] = x;
    transform->elements[3][1] = y;
    transform->elements[3][2] = z;
}

void func_800D1808(void *destination, float x, float y, float z) {
    TransformStorage storage;

    func_800C4440(&storage.transform);
    storage.transform.elements[3][0] = x;
    storage.transform.elements[3][1] = y;
    storage.transform.elements[3][2] = z;
    func_800C4340(&storage.transform, destination);
}
