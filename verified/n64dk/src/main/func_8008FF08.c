typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;

typedef struct SupermanEntry {
    u8 pad00[0x14];
    s16 active;
    s16 flags;
    u8 pad18[0x18];
} SupermanEntry;

extern SupermanEntry *D_800D8144[];

void func_8008FF08(s32 arg0) {
    SupermanEntry *entry;

    entry = D_800D8144[arg0];
    if ((entry != 0) && (entry->active != 0)) {
        do {
            entry->flags &= ~1;
            entry++;
        } while (entry->active != 0);
    }
}
