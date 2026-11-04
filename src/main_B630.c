extern unsigned char D_8013B730[];
extern int D_8013B650;
extern int D_8013B654;
extern int D_800DBAA0;
extern int D_800DBAA8;
extern int D_800DBAAC;

extern void func_800CD3AC(int arg0, ...);
extern void func_8000A640(int x, int y);

void func_8000AA30(void) {
    int column;
    int row;

    for (row = 10; row < 21; row++) {
        for (column = 10; column < 21; column++) {
            func_800CD3AC((int)&D_800DBAA0,
                          D_8013B730[row * 31 + column]);
        }
        func_800CD3AC((int)&D_800DBAA8);
    }
    func_800CD3AC((int)&D_800DBAAC);
}

void func_8000AAC4(float x, float y, int reverse) {
    int first;
    int second;
    int row;
    int temporary;

    first = (D_8013B654 + x) / D_8013B650;
    second = (x - D_8013B654) / D_8013B650;
    row = y / D_8013B650;
    if (reverse != 1) {
        temporary = second;
        second = first;
        first = temporary;
    }
    func_8000A640(first, row);
    func_8000A640(second, row);
}
