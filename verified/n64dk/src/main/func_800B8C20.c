typedef signed short s16;
typedef unsigned char u8;
typedef float f32;
typedef struct Entry { u8 pad[0x10]; f32 value10; u8 rest[0x14]; } Entry;
typedef struct Object { u8 pad00[8]; u8 entryIndex; u8 pad09[7]; Entry *entries; u8 pad14[0x18]; u8 sub2C[0xC]; f32 scale38; u8 pad3C[0xA8]; f32 valueE4; } Object;
extern void func_800B8728(void *);
extern void func_800B894C(Object *);
extern f32 D_801442C4;
extern s16 D_80144352;
void func_800B8C20(Object *arg0) {
    Entry *entry;
    entry = &arg0->entries[arg0->entryIndex];
    func_800B894C(arg0);
    if (D_80144352 != 0) {
        func_800B8728(arg0->sub2C);
        arg0->valueE4 = arg0->scale38 * D_801442C4 + entry->value10;
    }
}
