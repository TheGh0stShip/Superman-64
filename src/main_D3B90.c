typedef unsigned int u32;

void func_800D2F90(u32 value) {
    *(volatile u32 *)0xA4040010 = value;
}
