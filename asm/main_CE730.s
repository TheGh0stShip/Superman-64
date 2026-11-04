.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel func_800CDB30
/* CE730 800CDB30 27BDFFD8 */  addiu      $sp, $sp, -0x28
/* CE734 800CDB34 AFBF001C */  sw         $ra, 0x1c($sp)
/* CE738 800CDB38 AFA40028 */  sw         $a0, 0x28($sp)
/* CE73C 800CDB3C AFA5002C */  sw         $a1, 0x2c($sp)
/* CE740 800CDB40 AFA60030 */  sw         $a2, 0x30($sp)
/* CE744 800CDB44 AFB10018 */  sw         $s1, 0x18($sp)
/* CE748 800CDB48 0C033DD4 */  jal        func_800CF750
/* CE74C 800CDB4C AFB00014 */   sw        $s0, 0x14($sp)
/* CE750 800CDB50 8FAE0028 */  lw         $t6, 0x28($sp)
/* CE754 800CDB54 00408025 */  or         $s0, $v0, $zero
/* CE758 800CDB58 8DCF0008 */  lw         $t7, 8($t6)
/* CE75C 800CDB5C 8DD80010 */  lw         $t8, 0x10($t6)
/* CE760 800CDB60 01F8082A */  slt        $at, $t7, $t8
/* CE764 800CDB64 14200018 */  bnez       $at, .L800CDBC8
/* CE768 800CDB68 00000000 */   nop
.L800CDB6C:
/* CE76C 800CDB6C 8FB90030 */  lw         $t9, 0x30($sp)
/* CE770 800CDB70 24010001 */  addiu      $at, $zero, 1
/* CE774 800CDB74 1721000A */  bne        $t9, $at, .L800CDBA0
/* CE778 800CDB78 00000000 */   nop
/* CE77C 800CDB7C 3C09800E */  lui        $t1, %hi(D_800DA080)
/* CE780 800CDB80 8D29A080 */  lw         $t1, %lo(D_800DA080)($t1)
/* CE784 800CDB84 24080008 */  addiu      $t0, $zero, 8
/* CE788 800CDB88 A5280010 */  sh         $t0, 0x10($t1)
/* CE78C 800CDB8C 8FA40028 */  lw         $a0, 0x28($sp)
/* CE790 800CDB90 0C02FAFF */  jal        func_800BEBFC
/* CE794 800CDB94 24840004 */   addiu     $a0, $a0, 4
/* CE798 800CDB98 10000005 */  b          .L800CDBB0
/* CE79C 800CDB9C 00000000 */   nop
.L800CDBA0:
/* CE7A0 800CDBA0 0C033DDC */  jal        func_800CF770
/* CE7A4 800CDBA4 02002025 */   or        $a0, $s0, $zero
/* CE7A8 800CDBA8 10000030 */  b          .L800CDC6C
/* CE7AC 800CDBAC 2402FFFF */   addiu     $v0, $zero, -1
.L800CDBB0:
/* CE7B0 800CDBB0 8FAA0028 */  lw         $t2, 0x28($sp)
/* CE7B4 800CDBB4 8D4B0008 */  lw         $t3, 8($t2)
/* CE7B8 800CDBB8 8D4C0010 */  lw         $t4, 0x10($t2)
/* CE7BC 800CDBBC 016C082A */  slt        $at, $t3, $t4
/* CE7C0 800CDBC0 1020FFEA */  beqz       $at, .L800CDB6C
/* CE7C4 800CDBC4 00000000 */   nop
.L800CDBC8:
/* CE7C8 800CDBC8 8FAD0028 */  lw         $t5, 0x28($sp)
/* CE7CC 800CDBCC 8DAE000C */  lw         $t6, 0xc($t5)
/* CE7D0 800CDBD0 8DAF0010 */  lw         $t7, 0x10($t5)
/* CE7D4 800CDBD4 01CFC021 */  addu       $t8, $t6, $t7
/* CE7D8 800CDBD8 2719FFFF */  addiu      $t9, $t8, -1
/* CE7DC 800CDBDC 032F001A */  div        $zero, $t9, $t7
/* CE7E0 800CDBE0 00004010 */  mfhi       $t0
/* CE7E4 800CDBE4 ADA8000C */  sw         $t0, 0xc($t5)
/* CE7E8 800CDBE8 8FAA0028 */  lw         $t2, 0x28($sp)
/* CE7EC 800CDBEC 8FA9002C */  lw         $t1, 0x2c($sp)
/* CE7F0 800CDBF0 15E00002 */  bnez       $t7, .L800CDBFC
/* CE7F4 800CDBF4 00000000 */   nop
/* CE7F8 800CDBF8 0007000D */  break      7
.L800CDBFC:
/* CE7FC 800CDBFC 2401FFFF */   addiu     $at, $zero, -1
/* CE800 800CDC00 15E10004 */  bne        $t7, $at, .L800CDC14
/* CE804 800CDC04 3C018000 */   lui       $at, 0x8000
/* CE808 800CDC08 17210002 */  bne        $t9, $at, .L800CDC14
/* CE80C 800CDC0C 00000000 */   nop
/* CE810 800CDC10 0006000D */  break      6
.L800CDC14:
/* CE814 800CDC14 8D4C000C */   lw        $t4, 0xc($t2)
/* CE818 800CDC18 8D4B0014 */  lw         $t3, 0x14($t2)
/* CE81C 800CDC1C 000C7080 */  sll        $t6, $t4, 2
/* CE820 800CDC20 016EC021 */  addu       $t8, $t3, $t6
/* CE824 800CDC24 AF090000 */  sw         $t1, ($t8)
/* CE828 800CDC28 8FB90028 */  lw         $t9, 0x28($sp)
/* CE82C 800CDC2C 8F2F0008 */  lw         $t7, 8($t9)
/* CE830 800CDC30 25E80001 */  addiu      $t0, $t7, 1
/* CE834 800CDC34 AF280008 */  sw         $t0, 8($t9)
/* CE838 800CDC38 8FAD0028 */  lw         $t5, 0x28($sp)
/* CE83C 800CDC3C 8DAA0000 */  lw         $t2, ($t5)
/* CE840 800CDC40 8D4C0000 */  lw         $t4, ($t2)
/* CE844 800CDC44 11800006 */  beqz       $t4, .L800CDC60
/* CE848 800CDC48 00000000 */   nop
/* CE84C 800CDC4C 0C02FB51 */  jal        func_800BED44
/* CE850 800CDC50 01A02025 */   or        $a0, $t5, $zero
/* CE854 800CDC54 00408825 */  or         $s1, $v0, $zero
/* CE858 800CDC58 0C034CE8 */  jal        func_800D33A0
/* CE85C 800CDC5C 02202025 */   or        $a0, $s1, $zero
.L800CDC60:
/* CE860 800CDC60 0C033DDC */  jal        func_800CF770
/* CE864 800CDC64 02002025 */   or        $a0, $s0, $zero
/* CE868 800CDC68 00001025 */  or         $v0, $zero, $zero
.L800CDC6C:
/* CE86C 800CDC6C 8FBF001C */  lw         $ra, 0x1c($sp)
/* CE870 800CDC70 8FB00014 */  lw         $s0, 0x14($sp)
/* CE874 800CDC74 8FB10018 */  lw         $s1, 0x18($sp)
/* CE878 800CDC78 03E00008 */  jr         $ra
/* CE87C 800CDC7C 27BD0028 */   addiu     $sp, $sp, 0x28
