.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel func_800C4340
/* C4F40 800C4340 3C014780 */  lui        $at, 0x4780
/* C4F44 800C4344 44810000 */  mtc1       $at, $f0
/* C4F48 800C4348 00A01025 */  or         $v0, $a1, $zero
/* C4F4C 800C434C 24A30020 */  addiu      $v1, $a1, 0x20
/* C4F50 800C4350 00003025 */  or         $a2, $zero, $zero
/* C4F54 800C4354 00803825 */  or         $a3, $a0, $zero
/* C4F58 800C4358 240C0004 */  addiu      $t4, $zero, 4
/* C4F5C 800C435C 240B0002 */  addiu      $t3, $zero, 2
/* C4F60 800C4360 3C0AFFFF */  lui        $t2, 0xffff
.L800C4364:
/* C4F64 800C4364 00002025 */  or         $a0, $zero, $zero
/* C4F68 800C4368 00E04025 */  or         $t0, $a3, $zero
/* C4F6C 800C436C C50E0004 */  lwc1       $f14, 4($t0)
/* C4F70 800C4370 24840001 */  addiu      $a0, $a0, 1
/* C4F74 800C4374 C5120000 */  lwc1       $f18, ($t0)
/* C4F78 800C4378 46007402 */  mul.s      $f16, $f14, $f0
/* C4F7C 800C437C 108B0019 */  beq        $a0, $t3, .L800C43E4
/* C4F80 800C4380 00000000 */   nop
.L800C4384:
/* C4F84 800C4384 46009382 */  mul.s      $f14, $f18, $f0
/* C4F88 800C4388 24840001 */  addiu      $a0, $a0, 1
/* C4F8C 800C438C 24420004 */  addiu      $v0, $v0, 4
/* C4F90 800C4390 24630004 */  addiu      $v1, $v1, 4
/* C4F94 800C4394 25080008 */  addiu      $t0, $t0, 8
/* C4F98 800C4398 4600830D */  trunc.w.s  $f12, $f16
/* C4F9C 800C439C 4600738D */  trunc.w.s  $f14, $f14
/* C4FA0 800C43A0 44096000 */  mfc1       $t1, $f12
/* C4FA4 800C43A4 44057000 */  mfc1       $a1, $f14
/* C4FA8 800C43A8 0009CC03 */  sra        $t9, $t1, 0x10
/* C4FAC 800C43AC 332DFFFF */  andi       $t5, $t9, 0xffff
/* C4FB0 800C43B0 00AAC024 */  and        $t8, $a1, $t2
/* C4FB4 800C43B4 030D7025 */  or         $t6, $t8, $t5
/* C4FB8 800C43B8 00057C00 */  sll        $t7, $a1, 0x10
/* C4FBC 800C43BC 01EAC824 */  and        $t9, $t7, $t2
/* C4FC0 800C43C0 AC4EFFFC */  sw         $t6, -4($v0)
/* C4FC4 800C43C4 3138FFFF */  andi       $t8, $t1, 0xffff
/* C4FC8 800C43C8 03386825 */  or         $t5, $t9, $t8
/* C4FCC 800C43CC AC6DFFFC */  sw         $t5, -4($v1)
/* C4FD0 800C43D0 C50E0004 */  lwc1       $f14, 4($t0)
/* C4FD4 800C43D4 C5120000 */  lwc1       $f18, ($t0)
/* C4FD8 800C43D8 46007402 */  mul.s      $f16, $f14, $f0
/* C4FDC 800C43DC 148BFFE9 */  bne        $a0, $t3, .L800C4384
/* C4FE0 800C43E0 00000000 */   nop
.L800C43E4:
/* C4FE4 800C43E4 46009382 */  mul.s      $f14, $f18, $f0
/* C4FE8 800C43E8 25080008 */  addiu      $t0, $t0, 8
/* C4FEC 800C43EC 24420004 */  addiu      $v0, $v0, 4
/* C4FF0 800C43F0 24630004 */  addiu      $v1, $v1, 4
/* C4FF4 800C43F4 4600830D */  trunc.w.s  $f12, $f16
/* C4FF8 800C43F8 4600738D */  trunc.w.s  $f14, $f14
/* C4FFC 800C43FC 44096000 */  mfc1       $t1, $f12
/* C5000 800C4400 44057000 */  mfc1       $a1, $f14
/* C5004 800C4404 0009CC03 */  sra        $t9, $t1, 0x10
/* C5008 800C4408 332DFFFF */  andi       $t5, $t9, 0xffff
/* C500C 800C440C 00AAC024 */  and        $t8, $a1, $t2
/* C5010 800C4410 030D7025 */  or         $t6, $t8, $t5
/* C5014 800C4414 00057C00 */  sll        $t7, $a1, 0x10
/* C5018 800C4418 01EAC824 */  and        $t9, $t7, $t2
/* C501C 800C441C 3138FFFF */  andi       $t8, $t1, 0xffff
/* C5020 800C4420 AC4EFFFC */  sw         $t6, -4($v0)
/* C5024 800C4424 03386825 */  or         $t5, $t9, $t8
/* C5028 800C4428 AC6DFFFC */  sw         $t5, -4($v1)
/* C502C 800C442C 24C60001 */  addiu      $a2, $a2, 1
/* C5030 800C4430 14CCFFCC */  bne        $a2, $t4, .L800C4364
/* C5034 800C4434 24E70010 */   addiu     $a3, $a3, 0x10
/* C5038 800C4438 03E00008 */  jr         $ra
/* C503C 800C443C 00000000 */   nop
