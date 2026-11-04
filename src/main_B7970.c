typedef struct {
    char pad0[8];
    int type;
    int angle;
    char pad10[4];
    float x;
    char pad18[4];
    float z;
} TrackEntry;

extern double D_800DF410;
extern double D_800DF418;

float func_800BE410(float angle);
float func_800CFC60(float angle);

void func_800B6D70(TrackEntry *entry) {
    float angle;
    register float offset;

    if (entry == 0) {
        return;
    }

    if (entry->type != -0x40) {
        do {
            if (entry->type == 6) {
                entry++;
                angle = (float)((double)(float)entry->angle / 100.0);
                offset = func_800BE410(angle);
                entry->x = (float)((double)entry->x -
                                   (double)offset * D_800DF410);
                offset = func_800CFC60(angle);
                entry->z = (float)((double)entry->z -
                                   (double)offset * D_800DF418);
            }
            entry++;
        } while (entry->type != -0x40);
    }
}
