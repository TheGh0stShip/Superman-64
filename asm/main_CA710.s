.include "macro.inc"
.set noat
.set noreorder
.set gp=64
.section .text, "ax"
glabel func_800C9B10
addiu $sp, $sp, -0x40
lw $t0, 0x50($sp)
sw $ra, 0x3c($sp)
sw $s6, 0x38($sp)
sw $s5, 0x34($sp)
sw $s4, 0x30($sp)
sw $s3, 0x2c($sp)
sw $s2, 0x28($sp)
sw $s1, 0x24($sp)
sw $s0, 0x20($sp)
lw $v1, 0x1c($a0)
lui $t6, 0x200
sll $v0, $a2, 1
lui $t7, 0x200
ori $t6, $t6, 0x6c0
ori $t7, $t7, 0x800
sw $t6, ($t0)
sw $v0, 4($t0)
sw $t7, 8($t0)
sw $v0, 0xc($t0)
lw $t8, 0x14($a0)
or $s4, $a2, $zero
or $s5, $a1, $zero
or $s6, $a3, $zero
or $s3, $a0, $zero
or $s0, $zero, $zero
blez $t8, .L800C9BBC
 addiu $s2, $t0, 0x10
or $s1, $v1, $zero
.L800C9B84:
lw $a0, ($s1)
sw $s2, 0x10($sp)
or $a1, $s5, $zero
lw $t9, 4($a0)
or $a2, $s4, $zero
or $a3, $s6, $zero
jalr $t9
 nop
lw $t1, 0x14($s3)
addiu $s0, $s0, 1
addiu $s1, $s1, 4
slt $at, $s0, $t1
bnez $at, .L800C9B84
 or $s2, $v0, $zero
.L800C9BBC:
lw $ra, 0x3c($sp)
or $v0, $s2, $zero
lw $s2, 0x28($sp)
lw $s0, 0x20($sp)
lw $s1, 0x24($sp)
lw $s3, 0x2c($sp)
lw $s4, 0x30($sp)
lw $s5, 0x34($sp)
lw $s6, 0x38($sp)
jr $ra
 addiu $sp, $sp, 0x40
nop
nop
