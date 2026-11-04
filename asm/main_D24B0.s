.include "macro.inc"
.set noat
.set noreorder
.set gp=64
.section .text, "ax"
glabel func_800D18B0
addiu $sp, $sp, -0x20
sw $ra, 0x14($sp)
sw $a1, 0x24($sp)
sw $a2, 0x28($sp)
sw $a3, 0x2c($sp)
lw $t6, 8($a1)
beql $t6, $zero, .L800D1988
 lw $ra, 0x14($sp)
sw $a0, 0x20($sp)
jal func_800C7FD0
 sw $a1, 0x24($sp)
lw $a0, 0x20($sp)
lw $a3, 0x24($sp)
beqz $v0, .L800D1984
 or $a2, $v0, $zero
lbu $v1, 0x3b($sp)
bgez $v1, .L800D1904
 or $v0, $v1, $zero
negu $v1, $v0
andi $t7, $v1, 0xff
or $v1, $t7, $zero
.L800D1904:
lw $t9, 8($a3)
lw $t8, 0x1c($a0)
addiu $t2, $zero, 0xd
lw $t0, 0xd8($t9)
sw $zero, ($a2)
sh $t2, 8($a2)
addu $t1, $t8, $t0
sw $t1, 4($a2)
lh $t3, 0x1a($a3)
sh $t3, 0xa($a2)
lbu $t4, 0x37($sp)
sb $t4, 0x12($a2)
lh $t5, 0x32($sp)
sb $v1, 0x13($a2)
sh $t5, 0x10($a2)
lwc1 $f4, 0x2c($sp)
swc1 $f4, 0xc($a2)
sw $a3, 0x24($sp)
sw $a2, 0x1c($sp)
jal func_800C7EC8
 lw $a1, 0x3c($sp)
lw $a2, 0x1c($sp)
lw $a3, 0x24($sp)
addiu $a1, $zero, 3
sw $v0, 0x14($a2)
lw $t6, 0x28($sp)
sw $t6, 0x18($a2)
lw $t7, 8($a3)
lw $a0, 0xc($t7)
lw $t9, 8($a0)
jalr $t9
 nop
.L800D1984:
lw $ra, 0x14($sp)
.L800D1988:
addiu $sp, $sp, 0x20
jr $ra
 nop
nop
nop
nop
