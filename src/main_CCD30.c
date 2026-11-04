typedef unsigned int u32;

typedef struct {
    u32 first;
    u32 second;
} PiHandle;

extern PiHandle D_80146B80[];
extern u32 func_800CF750(void);
extern void func_800CF770(u32 mask);

void func_800CC130(u32 index, u32 first, u32 second) {
    register u32 mask = func_800CF750();
    PiHandle *handle = &D_80146B80[index];

    handle->first = first;
    handle->second = second;
    func_800CF770(mask);
}
