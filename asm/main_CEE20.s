.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel func_800CE2A0
/* CEEA0 800CE2A0 00057400 */  sll        $t6, $a1, 0x10
/* CEEA4 800CE2A4 000E7C03 */  sra        $t7, $t6, 0x10
/* CEEA8 800CE2A8 AFA50004 */  sw         $a1, 4($sp)
/* CEEAC 800CE2AC 8C820040 */  lw         $v0, 0x40($a0)
/* CEEB0 800CE2B0 000F1880 */  sll        $v1, $t7, 2
/* CEEB4 800CE2B4 006F1823 */  subu       $v1, $v1, $t7
/* CEEB8 800CE2B8 00031900 */  sll        $v1, $v1, 4
/* CEEBC 800CE2BC 0062C021 */  addu       $t8, $v1, $v0
/* CEEC0 800CE2C0 8F190028 */  lw         $t9, 0x28($t8)
/* CEEC4 800CE2C4 00434021 */  addu       $t0, $v0, $v1
/* CEEC8 800CE2C8 17200007 */  bnez       $t9, .L800CE2E8
/* CEECC 800CE2CC 00000000 */   nop
/* CEED0 800CE2D0 AD00001C */  sw         $zero, 0x1c($t0)
/* CEED4 800CE2D4 8C89003C */  lw         $t1, 0x3c($a0)
/* CEED8 800CE2D8 240AFFFF */  addiu      $t2, $zero, -1
/* CEEDC 800CE2DC 15E90002 */  bne        $t7, $t1, .L800CE2E8
/* CEEE0 800CE2E0 00000000 */   nop
/* CEEE4 800CE2E4 AC8A003C */  sw         $t2, 0x3c($a0)
.L800CE2E8:
/* CEEE8 800CE2E8 03E00008 */  jr         $ra
/* CEEEC 800CE2EC 00000000 */   nop

glabel func_800CE2F0
/* CEEF0 800CE2F0 27BDFFC8 */  addiu      $sp, $sp, -0x38
/* CEEF4 800CE2F4 AFBF001C */  sw         $ra, 0x1c($sp)
/* CEEF8 800CE2F8 0C033DD4 */  jal        func_800CF750
/* CEEFC 800CE2FC AFB00018 */   sw        $s0, 0x18($sp)
/* CEF00 800CE300 0C031E2C */  jal        func_800C78B0
/* CEF04 800CE304 00408025 */   or        $s0, $v0, $zero
/* CEF08 800CE308 AFA20034 */  sw         $v0, 0x34($sp)
/* CEF0C 800CE30C 3C0F8014 */  lui        $t7, %hi(D_80146CB8)
/* CEF10 800CE310 8DEF6CB8 */  lw         $t7, %lo(D_80146CB8)($t7)
/* CEF14 800CE314 8FAE0034 */  lw         $t6, 0x34($sp)
/* CEF18 800CE318 3C088014 */  lui        $t0, %hi(D_80146CB0)
/* CEF1C 800CE31C 3C098014 */  lui        $t1, %hi(D_80146CB4)
/* CEF20 800CE320 8D296CB4 */  lw         $t1, %lo(D_80146CB4)($t1)
/* CEF24 800CE324 8D086CB0 */  lw         $t0, %lo(D_80146CB0)($t0)
/* CEF28 800CE328 01CFC023 */  subu       $t8, $t6, $t7
/* CEF2C 800CE32C AFB80030 */  sw         $t8, 0x30($sp)
/* CEF30 800CE330 02002025 */  or         $a0, $s0, $zero
/* CEF34 800CE334 AFA9002C */  sw         $t1, 0x2c($sp)
/* CEF38 800CE338 0C033DDC */  jal        func_800CF770
/* CEF3C 800CE33C AFA80028 */   sw        $t0, 0x28($sp)
/* CEF40 800CE340 8FB90030 */  lw         $t9, 0x30($sp)
/* CEF44 800CE344 8FAD002C */  lw         $t5, 0x2c($sp)
/* CEF48 800CE348 8FBF001C */  lw         $ra, 0x1c($sp)
/* CEF4C 800CE34C 03205825 */  or         $t3, $t9, $zero
/* CEF50 800CE350 016D1821 */  addu       $v1, $t3, $t5
/* CEF54 800CE354 8FAC0028 */  lw         $t4, 0x28($sp)
/* CEF58 800CE358 240A0000 */  addiu      $t2, $zero, 0
/* CEF5C 800CE35C 006D082B */  sltu       $at, $v1, $t5
/* CEF60 800CE360 002A1021 */  addu       $v0, $at, $t2
/* CEF64 800CE364 8FB00018 */  lw         $s0, 0x18($sp)
/* CEF68 800CE368 27BD0038 */  addiu      $sp, $sp, 0x38
/* CEF6C 800CE36C 03E00008 */  jr         $ra
/* CEF70 800CE370 004C1021 */   addu      $v0, $v0, $t4
/* CEF74 800CE374 00000000 */  nop
/* CEF78 800CE378 00000000 */  nop
/* CEF7C 800CE37C 00000000 */  nop
