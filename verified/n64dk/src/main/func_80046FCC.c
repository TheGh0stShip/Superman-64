typedef unsigned char u8;
typedef signed int s32;

typedef struct {
    s32 value0;
    s32 value4;
    u8 pad8[0x20];
} UnkRecord;

s32 func_80046FCC(UnkRecord *arg0, s32 arg1, s32 arg2) {
    s32 index;
    s32 count;

    index = 0;
    count = 0;
    if (arg0[index].value4 >= 0) {
        do {
            if ((((arg0[index].value0 != 0) && (arg2 != 0)) || (arg2 == 0)) &&
                    (arg0[index].value4 == arg1)) {
                count += 1;
            }
            index += 1;
        } while (arg0[index].value4 >= 0);
    }
    return count;
}
