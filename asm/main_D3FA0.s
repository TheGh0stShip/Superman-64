.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel func_800D34F0
/* D40F0 800D34F0 27BDFFE0 */  addiu      $sp, $sp, -0x20
/* D40F4 800D34F4 00054400 */  sll        $t0, $a1, 0x10
/* D40F8 800D34F8 00087403 */  sra        $t6, $t0, 0x10
/* D40FC 800D34FC AFB10018 */  sw         $s1, 0x18($sp)
/* D4100 800D3500 000E8880 */  sll        $s1, $t6, 2
/* D4104 800D3504 AFBF001C */  sw         $ra, 0x1c($sp)
/* D4108 800D3508 AFB00014 */  sw         $s0, 0x14($sp)
/* D410C 800D350C AFA50024 */  sw         $a1, 0x24($sp)
/* D4110 800D3510 022E8821 */  addu       $s1, $s1, $t6
/* D4114 800D3514 8C8F0034 */  lw         $t7, 0x34($a0)
/* D4118 800D3518 00118880 */  sll        $s1, $s1, 2
/* D411C 800D351C 022E8823 */  subu       $s1, $s1, $t6
/* D4120 800D3520 00808025 */  or         $s0, $a0, $zero
/* D4124 800D3524 00118880 */  sll        $s1, $s1, 2
/* D4128 800D3528 00C02825 */  or         $a1, $a2, $zero
/* D412C 800D352C 01F12021 */  addu       $a0, $t7, $s1
/* D4130 800D3530 24840020 */  addiu      $a0, $a0, 0x20
/* D4134 800D3534 0C032240 */  jal        func_800C8900
/* D4138 800D3538 00E03025 */   or        $a2, $a3, $zero
/* D413C 800D353C 8E180034 */  lw         $t8, 0x34($s0)
/* D4140 800D3540 24050001 */  addiu      $a1, $zero, 1
/* D4144 800D3544 03113021 */  addu       $a2, $t8, $s1
/* D4148 800D3548 0C0325E1 */  jal        func_800C9784
/* D414C 800D354C 24C40020 */   addiu     $a0, $a2, 0x20
/* D4150 800D3550 8E190034 */  lw         $t9, 0x34($s0)
/* D4154 800D3554 8E040030 */  lw         $a0, 0x30($s0)
/* D4158 800D3558 24050002 */  addiu      $a1, $zero, 2
/* D415C 800D355C 03313021 */  addu       $a2, $t9, $s1
/* D4160 800D3560 0C032350 */  jal        func_800C8D40
/* D4164 800D3564 24C60020 */   addiu     $a2, $a2, 0x20
/* D4168 800D3568 8E0A0034 */  lw         $t2, 0x34($s0)
/* D416C 800D356C 8FBF001C */  lw         $ra, 0x1c($sp)
/* D4170 800D3570 8FB00014 */  lw         $s0, 0x14($sp)
/* D4174 800D3574 01511021 */  addu       $v0, $t2, $s1
/* D4178 800D3578 8FB10018 */  lw         $s1, 0x18($sp)
/* D417C 800D357C 27BD0020 */  addiu      $sp, $sp, 0x20
/* D4180 800D3580 03E00008 */  jr         $ra
/* D4184 800D3584 24420020 */   addiu     $v0, $v0, 0x20
/* D4188 800D3588 00000000 */  nop
/* D418C 800D358C 00000000 */  nop
/* D4190 800D3590 00000000 */  nop
/* D4194 800D3594 00000000 */  nop
/* D4198 800D3598 00000000 */  nop
/* D419C 800D359C 00000000 */  nop
