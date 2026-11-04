typedef struct {
    int unk0;
    int id;
    unsigned int flags;
    unsigned char padC[0x1C];
} RuntimeEntry;

int func_800B7300(RuntimeEntry *entry, unsigned int mask,
                  unsigned int expected) {
    while (entry->id != -0x40) {
        if (entry->id == 0x206 && (entry->flags & mask) == expected) {
            return 1;
        }
        entry++;
    }
    return 0;
}

int func_800B7358(RuntimeEntry *entry) {
    return func_800B7300(entry, 0x8000, 0x8000);
}

int func_800B7384(RuntimeEntry *entry) {
    return func_800B7300(entry, 0xFF000000, 0x01000000);
}
