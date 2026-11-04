extern int D_802E2C10[][10];

void func_800A3170(void) {
    int index;
    D_802E2C10[58][0] = 0;
    D_802E2C10[59][0] = 1;
    for (index = 0; D_802E2C10[index][1] != -0x40; index += 1) {
        if (D_802E2C10[index][1] == 2 ||
            D_802E2C10[index][1] == 0xF0 ||
            D_802E2C10[index][1] == 0xFC ||
            D_802E2C10[index][1] == 0x3C) {
            D_802E2C10[index][0] = 0;
        }
    }
    D_802E2C10[45][0] = 1;
    D_802E2C10[46][0] = 1;
}
