typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

typedef struct {
    u32 word0;
    u32 word1;
} AudioCommand;

typedef struct AudioFilter AudioFilter;
typedef AudioCommand *(*AudioHandler)(void *, s16 *, s32, s32,
                                      AudioCommand *);

struct AudioFilter {
    void *source;
    AudioHandler handler;
};

typedef struct {
    unsigned char pad00[0x14];
    s32 source_count;
    unsigned char pad18[4];
    AudioFilter **sources;
} AudioBus;

#define CLEAR_BUFFER(command, destination, count) \
    {                                               \
        AudioCommand *item = (AudioCommand *)(command); \
        item->word0 = 0x02000000 | (destination);   \
        item->word1 = (u32)(count);                 \
    }

AudioCommand *func_800C9B10(void *filter, s16 *output, s32 output_count,
                             s32 sample_offset, AudioCommand *commands) {
    AudioCommand *command;
    AudioBus *bus = filter;
    AudioFilter **sources = bus->sources;
    s32 i;

    CLEAR_BUFFER(commands, 0x6C0, output_count << 1);
    CLEAR_BUFFER(commands + 1, 0x800, output_count << 1);
    command = commands + 2;
    for (i = 0; i < bus->source_count; i++) {
        command = sources[i]->handler(sources[i], output, output_count,
                                      sample_offset, command);
    }
    return command;
}
