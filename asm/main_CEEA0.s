.include "macro.inc"
.set noat
.set noreorder
.set gp=64
.section .text, "ax"
glabel func_800CE2A0
sll $t6, $a1, 0x10
sra $t7, $t6, 0x10
sw $a1, 4($sp)
lw $v0, 0x40($a0)
sll $v1, $t7, 2
subu $v1, $v1, $t7
sll $v1, $v1, 4
addu $t8, $v1, $v0
lw $t9, 0x28($t8)
addu $t0, $v0, $v1
bnez $t9, .L800CE2E8
 nop
sw $zero, 0x1c($t0)
lw $t1, 0x3c($a0)
addiu $t2, $zero, -1
bne $t7, $t1, .L800CE2E8
 nop
sw $t2, 0x3c($a0)
.L800CE2E8:
jr $ra
 nop
