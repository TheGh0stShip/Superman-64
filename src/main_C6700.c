typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 byte0;
    u8 byte1;
    u8 byte2;
    u8 byte3;
    u8 byte4;
    u8 byte5;
    u8 byte6;
    u8 byte7;
} PackedEntry;

typedef struct {
    u16 value;
    u8 field2;
    u8 type;
} DecodedEntry;

extern PackedEntry D_80145890[];
extern u8 D_80145421;

void func_800C5B00(u8 *mask, DecodedEntry *output) {
    PackedEntry *entry;
    PackedEntry copy;
    int index;
    u8 result;

    result = 0;
    entry = D_80145890;
    index = 0;
    for (; index < D_80145421; index++, entry++, output++) {
        copy = *entry;
        output->type = (copy.byte2 & 0xC0) >> 4;
        if (output->type == 0) {
            output->value = (copy.byte5 << 8) | copy.byte4;
            output->field2 = copy.byte6;
            result |= 1 << index;
        }
    }
    *mask = result;
}
