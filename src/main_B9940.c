typedef struct {
    int value;
    int state;
    char pad08[0x20];
} RuntimeEntry;

extern RuntimeEntry *D_8015FF80;

void func_800B8D40(void) {
    RuntimeEntry *entry = D_8015FF80;

    while (entry->state != -0x40) {
        entry->value = 0;
        entry++;
    }
}
