typedef unsigned char u8;
typedef unsigned short u16;

u8 func_800CEB20(u16 address) {
    u8 crc = 0;
    u8 feedback;
    int i;

    for (i = 0; i < 16; i++) {
        feedback = (crc & 0x10) ? 0x15 : 0;
        crc <<= 1;
        crc |= (u8)((address & 0x400) ? 1 : 0);
        address <<= 1;
        crc ^= feedback;
    }
    return crc & 0x1F;
}

u8 func_800CEBD0(u8 *data) {
    u8 crc = 0;
    u8 feedback;
    int i;
    int j;

    for (i = 0; i <= 32; i++, data++) {
        for (j = 7; j >= 0; j--) {
            feedback = (crc & 0x80) ? 0x85 : 0;
            crc <<= 1;
            if (i == 32) {
                crc |= 0;
            } else {
                crc |= ((*data & (1 << j)) ? 1 : 0);
            }
            crc ^= feedback;
        }
    }
    return crc;
}
