#include "pfs.h"

s32 __osRepairPackId(OSPfs* pfs, OSPackId* badId, OSPackId* newId) {
    s32 result = 0;
    u8 data[32];
    u8 comparison[32];
    u8 mask = 0;
    int index;
    int bank;
    u16 addresses[4];

    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        result = __osPfsSelectBank(pfs);
        if (result != 0) {
            return result;
        }
    }
    newId->repaired = -1;
    newId->random = osGetCount();
    newId->serial_mid = badId->serial_mid;
    newId->serial_low = badId->serial_low;
    bank = 0;
    do {
        pfs->activebank = bank;
        result = __osPfsSelectBank(pfs);
        if (result != 0) {
            return result;
        }
        result = __osContRamRead(pfs->queue, pfs->channel, 0, data);
        if (result != 0) {
            return result;
        }
        data[0] = bank | 0x80;
        for (index = 1; index < 32; index++) {
            data[index] = ~data[index];
        }
        result = __osContRamWrite(pfs->queue, pfs->channel, 0, data, 0);
        if (result != 0) {
            return result;
        }
        result = __osContRamRead(pfs->queue, pfs->channel, 0, comparison);
        if (result != 0) {
            return result;
        }
        for (index = 0; index < 32; index++) {
            if (comparison[index] != data[index]) {
                break;
            }
        }
        if (index != 32) {
            break;
        }
        if (bank > 0) {
            pfs->activebank = 0;
            result = __osPfsSelectBank(pfs);
            if (result != 0) {
                return result;
            }
            result = __osContRamRead(pfs->queue, pfs->channel, 0, data);
            if (result != 0) {
                return result;
            }
            if (data[0] != 0x80) {
                break;
            }
        }
        bank++;
    } while (bank < 62);

    pfs->activebank = 0;
    result = __osPfsSelectBank(pfs);
    if (result != 0) {
        return result;
    }
    mask = bank > 0 ? 1 : 0;
    newId->deviceid = (badId->deviceid & (u16)~1) | mask;
    newId->banks = bank;
    newId->version = badId->version;
    __osIdCheckSum((u16*)newId, &newId->checksum,
                   &newId->inverted_checksum);
    addresses[0] = 1;
    addresses[1] = 3;
    addresses[2] = 4;
    addresses[3] = 6;
    for (index = 0; index < 4; index++) {
        result = __osContRamWrite(pfs->queue, pfs->channel,
                                  addresses[index], (u8*)newId, 1);
        if (result != 0) {
            return result;
        }
    }
    result = __osContRamRead(pfs->queue, pfs->channel, 1, data);
    if (result != 0) {
        return result;
    }
    for (index = 0; index < 32; index++) {
        if (data[index] != ((u8*)newId)[index]) {
            return 10;
        }
    }
    return 0;
}
