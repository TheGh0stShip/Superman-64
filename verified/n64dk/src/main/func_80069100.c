typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Entry {
    u8 pad[0xC];
    s32 value0C;
    s32 value10;
    u8 rest[0x14];
} Entry;

extern u32 D_8015F46C;
extern Entry D_8015F470[];

u32 func_80069100(s32 arg0, s32 arg1) {
    u32 i;
    Entry *entry;

    i = 0;
    if (D_8015F46C != 0) {
        do {
            entry = &D_8015F470[i];
            if (entry->value0C == arg0 && entry->value10 == arg1) {
                return i;
            }
        } while (++i < D_8015F46C);
    }
    return -1U;
}
