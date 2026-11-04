typedef unsigned char u8;

typedef struct {
    u8 pad00[0x2C];
    u8 text[0x20];
} RuntimeObject;

extern int func_800C7420(RuntimeObject *object);

int func_800D14B0(RuntimeObject *object, u8 *destination, int *count) {
    int index;

    if (destination == 0) {
        return 5;
    }
    if (func_800C7420(object) == 2) {
        return 2;
    }

    for (index = 0; index < 0x20; index++) {
        if (object->text[index] == 0) {
            break;
        }
        *destination = object->text[index];
        destination++;
    }
    *count = index;
    return 0;
}
