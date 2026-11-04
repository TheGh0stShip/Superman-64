typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct { u8 *curPtr; s32 lastTicks; s32 curTicks; s16 lastStatus; } ALSeqMarker;
typedef struct { s32 ticks; u8 status; u8 byte1; u8 byte2; u32 duration; } ALMIDIEvent;
typedef struct { s32 ticks; u8 status; u8 type; u8 len; u8 byte1; u8 byte2; u8 byte3; } ALTempoEvent;
typedef struct { s32 ticks; u8 status; u8 type; u8 len; } ALEndEvent;
typedef struct {
    s16 type;
    union { ALMIDIEvent midi; ALTempoEvent tempo; ALEndEvent end; } msg;
} ALEvent;
typedef struct {
    u8 *base;
    u8 *trackStart;
    u8 *curPtr;
    s32 lastTicks;
    s32 len;
    f32 qnpt;
    s16 division;
    s16 lastStatus;
} ALSeq;

extern const double D_800DFBD0;
extern const double D_800DFBD8;

#define IFF_FILE_HDR 0x4D546864
#define IFF_TRACK_HDR 0x4D54726B
#define AL_SEQ_MIDI_EVT 1
#define AL_TEMPO_EVT 3
#define AL_SEQ_END_EVT 4
#define AL_MIDI_PROGRAM_CHANGE 0xC0
#define AL_MIDI_CHANNEL_PRESSURE 0xD0
#define AL_MIDI_META 0xFF
#define AL_MIDI_META_TEMPO 0x51
#define AL_MIDI_META_EOT 0x2F

static s32 read_var_len(ALSeq *sequence);
static u8 read_u8(ALSeq *sequence);
static s16 read_s16(ALSeq *sequence);
static s32 read_s32(ALSeq *sequence);

void func_800C3008(ALSeq *sequence, u8 *data, s32 length) {
    sequence->base = data;
    sequence->len = length;
    sequence->lastStatus = 0;
    sequence->lastTicks = 0;
    sequence->curPtr = data;
    if (read_s32(sequence) != IFF_FILE_HDR) return;
    read_s32(sequence);
    if (read_s16(sequence) != 0) return;
    if (read_s16(sequence) != 1) return;
    sequence->division = read_s16(sequence);
    if (sequence->division & 0x8000) return;
    sequence->qnpt = 1.0 / (f32)sequence->division;
    if (read_s32(sequence) != IFF_TRACK_HDR) return;
    read_s32(sequence);
    sequence->trackStart = sequence->curPtr;
}

void func_800C2B54(ALSeq *sequence, ALEvent *event) {
    u8 status;
    s32 delta_ticks;
    delta_ticks = read_var_len(sequence);
    sequence->lastTicks += delta_ticks;
    status = read_u8(sequence);
    if (status == AL_MIDI_META) {
        u8 type = read_u8(sequence);
        if (type == AL_MIDI_META_TEMPO) {
            event->type = AL_TEMPO_EVT;
            event->msg.tempo.ticks = delta_ticks;
            event->msg.tempo.status = status;
            event->msg.tempo.type = type;
            event->msg.tempo.len = read_u8(sequence);
            event->msg.tempo.byte1 = read_u8(sequence);
            event->msg.tempo.byte2 = read_u8(sequence);
            event->msg.tempo.byte3 = read_u8(sequence);
        } else if (type == AL_MIDI_META_EOT) {
            event->type = AL_SEQ_END_EVT;
            event->msg.end.ticks = delta_ticks;
            event->msg.end.status = status;
            event->msg.end.type = type;
            event->msg.end.len = read_u8(sequence);
        }
        sequence->lastStatus = 0;
    } else {
        event->type = AL_SEQ_MIDI_EVT;
        event->msg.midi.ticks = delta_ticks;
        if (status & 0x80) {
            event->msg.midi.status = status;
            event->msg.midi.byte1 = read_u8(sequence);
            sequence->lastStatus = status;
        } else {
            event->msg.midi.status = sequence->lastStatus;
            event->msg.midi.byte1 = status;
        }
        if (((event->msg.midi.status & 0xF0) != AL_MIDI_PROGRAM_CHANGE) &&
            ((event->msg.midi.status & 0xF0) != AL_MIDI_CHANNEL_PRESSURE)) {
            event->msg.midi.byte2 = read_u8(sequence);
        } else {
            event->msg.midi.byte2 = 0;
        }
    }
}

char func_800C2F30(ALSeq *sequence, s32 *delta_ticks) {
    u8 *saved_pointer;
    if (sequence->curPtr >= sequence->base + sequence->len) return 0;
    saved_pointer = sequence->curPtr;
    *delta_ticks = read_var_len(sequence);
    sequence->curPtr = saved_pointer;
    return 1;
}

f32 func_800C2EDC(ALSeq *sequence, s32 ticks, u32 tempo) {
    return (f32)(((f32)ticks * (f32)tempo) /
                 ((f32)sequence->division * D_800DFBD8));
}

u32 func_800C2DF8(ALSeq *sequence, f32 seconds, u32 tempo) {
    return (u32)(((seconds * D_800DFBD0) * sequence->division) / tempo);
}

void func_800C2CD8(ALSeq *sequence, ALSeqMarker *marker, u32 ticks) {
    ALEvent event;
    u8 *saved_pointer, *last_pointer;
    s32 saved_ticks, last_ticks;
    s16 saved_status, last_status;
    if (ticks == 0) {
        marker->curPtr = sequence->trackStart;
        marker->lastStatus = 0;
        marker->lastTicks = 0;
        marker->curTicks = 0;
        return;
    } else {
        saved_pointer = sequence->curPtr;
        saved_status = sequence->lastStatus;
        saved_ticks = sequence->lastTicks;
        sequence->curPtr = sequence->trackStart;
        sequence->lastStatus = 0;
        sequence->lastTicks = 0;
        do {
            last_pointer = sequence->curPtr;
            last_status = sequence->lastStatus;
            last_ticks = sequence->lastTicks;
            func_800C2B54(sequence, &event);
            if (event.type == AL_SEQ_END_EVT) {
                last_pointer = sequence->curPtr;
                last_status = sequence->lastStatus;
                last_ticks = sequence->lastTicks;
                break;
            }
        } while (sequence->lastTicks < ticks);
        marker->curPtr = last_pointer;
        marker->lastStatus = last_status;
        marker->lastTicks = last_ticks;
        marker->curTicks = sequence->lastTicks;
        sequence->curPtr = saved_pointer;
        sequence->lastStatus = saved_status;
        sequence->lastTicks = saved_ticks;
    }
}

s32 func_800C2AF8(ALSeq *sequence) { return sequence->lastTicks; }

void func_800C2ADC(ALSeq *sequence, ALSeqMarker *marker) {
    sequence->curPtr = marker->curPtr;
    sequence->lastStatus = marker->lastStatus;
    sequence->lastTicks = marker->lastTicks;
}

void func_800C2AC0(ALSeq *sequence, ALSeqMarker *marker) {
    marker->curPtr = sequence->curPtr;
    marker->lastStatus = sequence->lastStatus;
    marker->lastTicks = sequence->lastTicks;
}

static u8 read_u8(ALSeq *sequence) { return *sequence->curPtr++; }

static s16 read_s16(ALSeq *sequence) {
    s16 value;
    value = *sequence->curPtr++ << 8;
    value |= *sequence->curPtr++;
    return value;
}

static s32 read_s32(ALSeq *sequence) {
    s32 value;
    value = *sequence->curPtr++ << 24;
    value |= *sequence->curPtr++ << 16;
    value |= *sequence->curPtr++ << 8;
    value |= *sequence->curPtr++;
    return value;
}

static s32 read_var_len(ALSeq *sequence) {
    s32 value, byte;
    byte = *sequence->curPtr++;
    value = byte;
    if (byte & 0x80) {
        value &= 0x7F;
        do {
            byte = *sequence->curPtr++;
            value = (value << 7) + (byte & 0x7F);
        } while (byte & 0x80);
    }
    return value;
}
