.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

.section .text.after_C08EF, "ax"
glabel func_800BFCF0
/* C08F0 800BFCF0 27BDFFD8 */  addiu      $sp, $sp, -0x28
/* C08F4 800BFCF4 AFA40028 */  sw         $a0, 0x28($sp)
/* C08F8 800BFCF8 AFA5002C */  sw         $a1, 0x2c($sp)
/* C08FC 800BFCFC 8FAE002C */  lw         $t6, 0x2c($sp)
/* C0900 800BFD00 8FAF0028 */  lw         $t7, 0x28($sp)
/* C0904 800BFD04 AFBF001C */  sw         $ra, 0x1c($sp)
/* C0908 800BFD08 AFA60030 */  sw         $a2, 0x30($sp)
/* C090C 800BFD0C AFA70034 */  sw         $a3, 0x34($sp)
/* C0910 800BFD10 AFB00018 */  sw         $s0, 0x18($sp)
/* C0914 800BFD14 ADEE0014 */  sw         $t6, 0x14($t7)
/* C0918 800BFD18 8FB90028 */  lw         $t9, 0x28($sp)
/* C091C 800BFD1C 8FB8003C */  lw         $t8, 0x3c($sp)
/* C0920 800BFD20 AF380004 */  sw         $t8, 4($t9)
/* C0924 800BFD24 8FA80028 */  lw         $t0, 0x28($sp)
/* C0928 800BFD28 AD000000 */  sw         $zero, ($t0)
/* C092C 800BFD2C 8FA90028 */  lw         $t1, 0x28($sp)
/* C0930 800BFD30 AD200008 */  sw         $zero, 8($t1)
/* C0934 800BFD34 8FAB0028 */  lw         $t3, 0x28($sp)
/* C0938 800BFD38 8FAA0030 */  lw         $t2, 0x30($sp)
/* C093C 800BFD3C AD6A011C */  sw         $t2, 0x11c($t3)
/* C0940 800BFD40 8FAC0034 */  lw         $t4, 0x34($sp)
/* C0944 800BFD44 8FAD0028 */  lw         $t5, 0x28($sp)
/* C0948 800BFD48 01807825 */  or         $t7, $t4, $zero
/* C094C 800BFD4C 000C77C3 */  sra        $t6, $t4, 0x1f
/* C0950 800BFD50 ADAE0038 */  sw         $t6, 0x38($t5)
/* C0954 800BFD54 ADAF003C */  sw         $t7, 0x3c($t5)
/* C0958 800BFD58 8FB80038 */  lw         $t8, 0x38($sp)
/* C095C 800BFD5C 8FB90028 */  lw         $t9, 0x28($sp)
/* C0960 800BFD60 3C0C800C */  lui        $t4, 0x800c
/* C0964 800BFD64 03004825 */  or         $t1, $t8, $zero
/* C0968 800BFD68 2D210010 */  sltiu      $at, $t1, 0x10
/* C096C 800BFD6C 001847C3 */  sra        $t0, $t8, 0x1f
/* C0970 800BFD70 01015023 */  subu       $t2, $t0, $at
/* C0974 800BFD74 252BFFF0 */  addiu      $t3, $t1, -0x10
/* C0978 800BFD78 AF2B00F4 */  sw         $t3, 0xf4($t9)
/* C097C 800BFD7C AF2A00F0 */  sw         $t2, 0xf0($t9)
/* C0980 800BFD80 8FAD0028 */  lw         $t5, 0x28($sp)
/* C0984 800BFD84 258CEED0 */  addiu      $t4, $t4, -0x1130
/* C0988 800BFD88 01807825 */  or         $t7, $t4, $zero
/* C098C 800BFD8C 000C77C3 */  sra        $t6, $t4, 0x1f
/* C0990 800BFD90 ADAE0100 */  sw         $t6, 0x100($t5)
/* C0994 800BFD94 ADAF0104 */  sw         $t7, 0x104($t5)
/* C0998 800BFD98 8FA90028 */  lw         $t1, 0x28($sp)
/* C099C 800BFD9C 3C18003F */  lui        $t8, 0x3f
/* C09A0 800BFDA0 3718FF01 */  ori        $t8, $t8, 0xff01
/* C09A4 800BFDA4 AFB80020 */  sw         $t8, 0x20($sp)
/* C09A8 800BFDA8 3408FF03 */  ori        $t0, $zero, 0xff03
/* C09AC 800BFDAC AD280118 */  sw         $t0, 0x118($t1)
/* C09B0 800BFDB0 8FAA0020 */  lw         $t2, 0x20($sp)
/* C09B4 800BFDB4 8FAC0028 */  lw         $t4, 0x28($sp)
/* C09B8 800BFDB8 3C01003F */  lui        $at, 0x3f
/* C09BC 800BFDBC 01415824 */  and        $t3, $t2, $at
/* C09C0 800BFDC0 000BCC02 */  srl        $t9, $t3, 0x10
/* C09C4 800BFDC4 AD990128 */  sw         $t9, 0x128($t4)
/* C09C8 800BFDC8 8FAF0028 */  lw         $t7, 0x28($sp)
/* C09CC 800BFDCC 3C0E0100 */  lui        $t6, 0x100
/* C09D0 800BFDD0 35CE0800 */  ori        $t6, $t6, 0x800
/* C09D4 800BFDD4 ADEE012C */  sw         $t6, 0x12c($t7)
/* C09D8 800BFDD8 8FAD0028 */  lw         $t5, 0x28($sp)
/* C09DC 800BFDDC 24180001 */  addiu      $t8, $zero, 1
/* C09E0 800BFDE0 ADA00018 */  sw         $zero, 0x18($t5)
/* C09E4 800BFDE4 8FA80028 */  lw         $t0, 0x28($sp)
/* C09E8 800BFDE8 A5180010 */  sh         $t8, 0x10($t0)
/* C09EC 800BFDEC 8FA90028 */  lw         $t1, 0x28($sp)
/* C09F0 800BFDF0 0C033DD4 */  jal        func_800CF750
/* C09F4 800BFDF4 A5200012 */   sh        $zero, 0x12($t1)
/* C09F8 800BFDF8 3C0A800E */  lui        $t2, %hi(D_800DA07C)
/* C09FC 800BFDFC 8D4AA07C */  lw         $t2, %lo(D_800DA07C)($t2)
/* C0A00 800BFE00 8FAB0028 */  lw         $t3, 0x28($sp)
/* C0A04 800BFE04 00408025 */  or         $s0, $v0, $zero
/* C0A08 800BFE08 3C01800E */  lui        $at, %hi(D_800DA07C)
/* C0A0C 800BFE0C AD6A000C */  sw         $t2, 0xc($t3)
/* C0A10 800BFE10 8FB90028 */  lw         $t9, 0x28($sp)
/* C0A14 800BFE14 02002025 */  or         $a0, $s0, $zero
/* C0A18 800BFE18 0C033DDC */  jal        func_800CF770
/* C0A1C 800BFE1C AC39A07C */   sw        $t9, %lo(D_800DA07C)($at)
/* C0A20 800BFE20 8FBF001C */  lw         $ra, 0x1c($sp)
/* C0A24 800BFE24 8FB00018 */  lw         $s0, 0x18($sp)
/* C0A28 800BFE28 27BD0028 */  addiu      $sp, $sp, 0x28
/* C0A2C 800BFE2C 03E00008 */  jr         $ra
/* C0A30 800BFE30 00000000 */   nop
/* C0A34 800BFE34 00000000 */  nop
/* C0A38 800BFE38 00000000 */  nop
/* C0A3C 800BFE3C 00000000 */  nop
