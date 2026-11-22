typedef unsigned char u8;
typedef signed int s32;

typedef struct Actor {
    u8 pad00[0x74];
    s32 typeIndex;
    u8 pad78[0x1F0];
    s32 state268;
    u8 pad26C[0x50];
    s32 state2BC;
    u8 pad2C0[0xC];
} Actor;

typedef struct TypeEntry {
    s32 flags;
    u8 pad04[0x38];
} TypeEntry;

s32 func_80156900(s32 arg0);
extern TypeEntry D_800D72F0[];
extern Actor *D_8015FB9C;

s32 func_8002C888(s32 arg0) {
    /* Retained by the original unoptimized build's debug stack layout. */
    s32 unused;

    if (!(D_800D72F0[D_8015FB9C[arg0].typeIndex].flags & 2) &&
        !(D_800D72F0[D_8015FB9C[arg0].typeIndex].flags & 4) &&
        D_8015FB9C[arg0].state268 == 1 &&
        D_8015FB9C[arg0].state2BC == 0) {
        return func_80156900(arg0);
    }
    return 0;
}
