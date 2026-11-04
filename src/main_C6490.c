typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 value;
    u8 flags;
    u8 type;
} DecodedEntry;

extern u8 D_80145421;
extern u8 D_80145890[];

void func_800BFC80(void);
void func_800BFCC4(void);
int func_800BE170(void *queue, void **message, int flags);
int func_800C3C00(int direction, void *buffer);
void func_800C5A30(u8 value);
void func_800C5B00(u8 *mask, DecodedEntry *output);

int func_800C5890(void *queue, u8 *result_mask) {
    int result = 0;
    void *message;
    u8 valid_mask;
    DecodedEntry entries[4];
    int index;
    u8 mask = 0;
    int retries = 3;

    func_800BFC80();
    do {
        func_800C5A30(0);
        result = func_800C3C00(1, D_80145890);
        func_800BE170(queue, &message, 1);
        result = func_800C3C00(0, D_80145890);
        func_800BE170(queue, &message, 1);
        func_800C5B00(&valid_mask, entries);

        for (index = 0; index < D_80145421; index++) {
            if ((entries[index].flags & 4) == 0) {
                retries--;
                break;
            }
        }
        if (index == D_80145421) {
            retries = 0;
        }
    } while (retries > 0);

    for (index = 0; index < D_80145421; index++) {
        if (entries[index].type == 0 && (entries[index].flags & 1)) {
            mask |= 1 << index;
        }
    }
    func_800BFCC4();
    *result_mask = mask;
    return result;
}
