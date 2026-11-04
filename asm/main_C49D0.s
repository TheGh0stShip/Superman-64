.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

glabel func_800C3DD0
/* C49D0 800C3DD0 27BDFFD0 */  addiu      $sp, $sp, -0x30
/* C49D4 800C3DD4 AFBF0014 */  sw         $ra, 0x14($sp)
/* C49D8 800C3DD8 8C820040 */  lw         $v0, 0x40($a0)
/* C49DC 800C3DDC A7A00020 */  sh         $zero, 0x20($sp)
/* C49E0 800C3DE0 8C8E003C */  lw         $t6, 0x3c($a0)
/* C49E4 800C3DE4 00A03025 */  or         $a2, $a1, $zero
/* C49E8 800C3DE8 27A50020 */  addiu      $a1, $sp, 0x20
/* C49EC 800C3DEC 000E7880 */  sll        $t7, $t6, 2
/* C49F0 800C3DF0 01EE7823 */  subu       $t7, $t7, $t6
/* C49F4 800C3DF4 000F7900 */  sll        $t7, $t7, 4
/* C49F8 800C3DF8 01E2C021 */  addu       $t8, $t7, $v0
/* C49FC 800C3DFC AFB80024 */  sw         $t8, 0x24($sp)
/* C4A00 800C3E00 0C03031B */  jal        func_800C0C6C
/* C4A04 800C3E04 24840014 */   addiu     $a0, $a0, 0x14
/* C4A08 800C3E08 8FBF0014 */  lw         $ra, 0x14($sp)
/* C4A0C 800C3E0C 27BD0030 */  addiu      $sp, $sp, 0x30
/* C4A10 800C3E10 03E00008 */  jr         $ra
/* C4A14 800C3E14 00000000 */   nop
/* C4A18 800C3E18 00000000 */  nop
/* C4A1C 800C3E1C 00000000 */  nop
