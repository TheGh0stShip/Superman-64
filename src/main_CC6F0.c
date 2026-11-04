typedef unsigned char u8;

typedef struct {
    u8 data[0x18];
} RuntimeQueue;

extern int D_800DB110;
extern void *D_80146B60;
extern RuntimeQueue D_80146B68;

extern void func_800CD510(RuntimeQueue *queue, void **buffer, int count);
extern int func_800BDEA0(RuntimeQueue *queue, void *message, int flag);
extern int func_800BE170(RuntimeQueue *queue, void **message, int flag);

void func_800CBAF0(void) {
    D_800DB110 = 1;
    func_800CD510(&D_80146B68, &D_80146B60, 1);
    func_800BDEA0(&D_80146B68, 0, 0);
}

void func_800CBB40(void) {
    void *message;

    if (D_800DB110 == 0) {
        func_800CBAF0();
    }
    func_800BE170(&D_80146B68, &message, 1);
}

void func_800CBB84(void) {
    func_800BDEA0(&D_80146B68, 0, 0);
}
