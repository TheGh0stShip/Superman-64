typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

typedef struct Acmd {
    struct {
        u32 w0;
        u32 w1;
    } words;
} Acmd;

#define SHIFT_LEFT(value, shift, width) \
    ((u32)(((u32)(value) & ((1 << (width)) - 1)) << (shift)))

#define SET_BUFFER(packet, count) { \
    Acmd *cmd = (Acmd *)(packet); \
    cmd->words.w0 = SHIFT_LEFT(8, 24, 8); \
    cmd->words.w1 = SHIFT_LEFT((count), 0, 16); \
}

#define INTERLEAVE(packet) { \
    Acmd *cmd = (Acmd *)(packet); \
    cmd->words.w0 = SHIFT_LEFT(13, 24, 8); \
    cmd->words.w1 = SHIFT_LEFT(0x440, 16, 16) | SHIFT_LEFT(0x580, 0, 16); \
}

#define SAVE_BUFFER(packet, address) { \
    Acmd *cmd = (Acmd *)(packet); \
    cmd->words.w0 = SHIFT_LEFT(6, 24, 8); \
    cmd->words.w1 = (u32)(address); \
}

typedef struct ALFilter ALFilter;

struct ALFilter {
    ALFilter *source;
    Acmd *(*handler)(void *, s16 *, s32, s32, Acmd *);
    u32 unknown8[3];
};

typedef struct ALSave {
    ALFilter filter;
    u32 dramout;
} ALSave;

typedef struct ALPlayer {
    struct ALPlayer *next;
} ALPlayer;

typedef struct ALSynth {
    ALPlayer *head;
} ALSynth;

extern u32 func_800C0A10(u32 mask);

s32 func_800CD710(void *filter, s32 param_id, void *param) {
    ALSave *save = filter;
    ALFilter *base = filter;
    u32 value = (u32)param;

    switch (param_id) {
        case 1:
            base->source = param;
            break;
        case 6:
            save->dramout = value;
            break;
    }
    return 0;
}

Acmd *func_800CD744(void *filter, s16 *out, s32 count, s32 sample_offset,
                    Acmd *commands) {
    ALSave *save = filter;
    ALFilter *source = save->filter.source;
    Acmd *command;

    command = source->handler(source, out, count, sample_offset, commands);

    SET_BUFFER(command++, count << 1);
    INTERLEAVE(command++);
    SET_BUFFER(command++, count << 2);
    SAVE_BUFFER(command++, save->dramout);

    return command;
}

void func_800CD7D0(ALSynth *synth, ALPlayer *client) {
    ALPlayer *player;
    ALPlayer *previous = 0;

    if (synth->head != 0) {
        u32 mask = func_800C0A10(1);

        for (player = synth->head; player != 0; player = player->next) {
            if (player == client) {
                if (previous != 0) {
                    previous->next = player->next;
                } else {
                    synth->head = player->next;
                }
                client->next = 0;
                break;
            }
            previous = player;
        }

        func_800C0A10(mask);
    }
}
