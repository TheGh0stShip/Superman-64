.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel func_800D3A40
/* D4640 800D3A40 27BDFFD0 */  addiu      $sp, $sp, -0x30
/* D4644 800D3A44 3C01800E */  lui        $at, %hi(D_800DFF20)
/* D4648 800D3A48 C424FF20 */  lwc1       $f4, %lo(D_800DFF20)($at)
/* D464C 800D3A4C AFB00018 */  sw         $s0, 0x18($sp)
/* D4650 800D3A50 00808025 */  or         $s0, $a0, $zero
/* D4654 800D3A54 3C018014 */  lui        $at, 0x8014
/* D4658 800D3A58 AFBF001C */  sw         $ra, 0x1c($sp)
/* D465C 800D3A5C AFA50034 */  sw         $a1, 0x34($sp)
/* D4660 800D3A60 AFA60038 */  sw         $a2, 0x38($sp)
/* D4664 800D3A64 AFA7003C */  sw         $a3, 0x3c($sp)
/* D4668 800D3A68 27A60040 */  addiu      $a2, $sp, 0x40
/* D466C 800D3A6C 27A5003C */  addiu      $a1, $sp, 0x3c
/* D4670 800D3A70 27A40038 */  addiu      $a0, $sp, 0x38
/* D4674 800D3A74 0C033B28 */  jal        func_800CECA0
/* D4678 800D3A78 E4247F00 */   swc1      $f4, 0x7f00($at)
/* D467C 800D3A7C 3C018014 */  lui        $at, %hi(D_80147F00)
/* D4680 800D3A80 C7AC0034 */  lwc1       $f12, 0x34($sp)
/* D4684 800D3A84 C4267F00 */  lwc1       $f6, %lo(D_80147F00)($at)
/* D4688 800D3A88 46066302 */  mul.s      $f12, $f12, $f6
/* D468C 800D3A8C 0C02F904 */  jal        func_800BE410
/* D4690 800D3A90 E7AC0034 */   swc1      $f12, 0x34($sp)
/* D4694 800D3A94 C7AC0034 */  lwc1       $f12, 0x34($sp)
/* D4698 800D3A98 0C033F18 */  jal        func_800CFC60
/* D469C 800D3A9C E7A0002C */   swc1      $f0, 0x2c($sp)
/* D46A0 800D3AA0 C7AE0038 */  lwc1       $f14, 0x38($sp)
/* D46A4 800D3AA4 C7B20040 */  lwc1       $f18, 0x40($sp)
/* D46A8 800D3AA8 E7A00028 */  swc1       $f0, 0x28($sp)
/* D46AC 800D3AAC 460E7202 */  mul.s      $f8, $f14, $f14
/* D46B0 800D3AB0 00000000 */  nop
/* D46B4 800D3AB4 46129282 */  mul.s      $f10, $f18, $f18
/* D46B8 800D3AB8 0C033068 */  jal        func_800CC1A0
/* D46BC 800D3ABC 460A4300 */   add.s     $f12, $f8, $f10
/* D46C0 800D3AC0 02002025 */  or         $a0, $s0, $zero
/* D46C4 800D3AC4 0C031110 */  jal        func_800C4440
/* D46C8 800D3AC8 E7A00024 */   swc1      $f0, 0x24($sp)
/* D46CC 800D3ACC 44806000 */  mtc1       $zero, $f12
/* D46D0 800D3AD0 C7AE0024 */  lwc1       $f14, 0x24($sp)
/* D46D4 800D3AD4 C7A20028 */  lwc1       $f2, 0x28($sp)
/* D46D8 800D3AD8 C7B0002C */  lwc1       $f16, 0x2c($sp)
/* D46DC 800D3ADC 460C7032 */  c.eq.s     $f14, $f12
/* D46E0 800D3AE0 3C013F80 */  lui        $at, 0x3f80
/* D46E4 800D3AE4 C7A6003C */  lwc1       $f6, 0x3c($sp)
/* D46E8 800D3AE8 45030041 */  bc1tl      .L800D3BF0
/* D46EC 800D3AEC 8FBF001C */   lw        $ra, 0x1c($sp)
/* D46F0 800D3AF0 44812000 */  mtc1       $at, $f4
/* D46F4 800D3AF4 46068202 */  mul.s      $f8, $f16, $f6
/* D46F8 800D3AF8 C7AA0038 */  lwc1       $f10, 0x38($sp)
/* D46FC 800D3AFC C7A60040 */  lwc1       $f6, 0x40($sp)
/* D4700 800D3B00 460E2003 */  div.s      $f0, $f4, $f14
/* D4704 800D3B04 460A4102 */  mul.s      $f4, $f8, $f10
/* D4708 800D3B08 46003207 */  neg.s      $f8, $f6
/* D470C 800D3B0C 46024282 */  mul.s      $f10, $f8, $f2
/* D4710 800D3B10 46045181 */  sub.s      $f6, $f10, $f4
/* D4714 800D3B14 46003202 */  mul.s      $f8, $f6, $f0
/* D4718 800D3B18 E6080000 */  swc1       $f8, ($s0)
/* D471C 800D3B1C C7AA003C */  lwc1       $f10, 0x3c($sp)
/* D4720 800D3B20 C7A60038 */  lwc1       $f6, 0x38($sp)
/* D4724 800D3B24 460A1102 */  mul.s      $f4, $f2, $f10
/* D4728 800D3B28 C7AA0040 */  lwc1       $f10, 0x40($sp)
/* D472C 800D3B2C 46062202 */  mul.s      $f8, $f4, $f6
/* D4730 800D3B30 00000000 */  nop
/* D4734 800D3B34 46105102 */  mul.s      $f4, $f10, $f16
/* D4738 800D3B38 46082181 */  sub.s      $f6, $f4, $f8
/* D473C 800D3B3C 46003282 */  mul.s      $f10, $f6, $f0
/* D4740 800D3B40 E60A0010 */  swc1       $f10, 0x10($s0)
/* D4744 800D3B44 460E8182 */  mul.s      $f6, $f16, $f14
/* D4748 800D3B48 C7A40038 */  lwc1       $f4, 0x38($sp)
/* D474C 800D3B4C E60C0030 */  swc1       $f12, 0x30($s0)
/* D4750 800D3B50 460E1282 */  mul.s      $f10, $f2, $f14
/* D4754 800D3B54 46002207 */  neg.s      $f8, $f4
/* D4758 800D3B58 E6080020 */  swc1       $f8, 0x20($s0)
/* D475C 800D3B5C E6060004 */  swc1       $f6, 4($s0)
/* D4760 800D3B60 E60A0014 */  swc1       $f10, 0x14($s0)
/* D4764 800D3B64 C7A4003C */  lwc1       $f4, 0x3c($sp)
/* D4768 800D3B68 E60C0034 */  swc1       $f12, 0x34($s0)
/* D476C 800D3B6C 46002207 */  neg.s      $f8, $f4
/* D4770 800D3B70 E6080024 */  swc1       $f8, 0x24($s0)
/* D4774 800D3B74 C7A6003C */  lwc1       $f6, 0x3c($sp)
/* D4778 800D3B78 C7A40040 */  lwc1       $f4, 0x40($sp)
/* D477C 800D3B7C 46068282 */  mul.s      $f10, $f16, $f6
/* D4780 800D3B80 C7A60038 */  lwc1       $f6, 0x38($sp)
/* D4784 800D3B84 46045202 */  mul.s      $f8, $f10, $f4
/* D4788 800D3B88 00000000 */  nop
/* D478C 800D3B8C 46061282 */  mul.s      $f10, $f2, $f6
/* D4790 800D3B90 46085101 */  sub.s      $f4, $f10, $f8
/* D4794 800D3B94 46008287 */  neg.s      $f10, $f16
/* D4798 800D3B98 46002182 */  mul.s      $f6, $f4, $f0
/* D479C 800D3B9C E6060008 */  swc1       $f6, 8($s0)
/* D47A0 800D3BA0 C7A80038 */  lwc1       $f8, 0x38($sp)
/* D47A4 800D3BA4 C7A6003C */  lwc1       $f6, 0x3c($sp)
/* D47A8 800D3BA8 46085102 */  mul.s      $f4, $f10, $f8
/* D47AC 800D3BAC C7A80040 */  lwc1       $f8, 0x40($sp)
/* D47B0 800D3BB0 46061282 */  mul.s      $f10, $f2, $f6
/* D47B4 800D3BB4 00000000 */  nop
/* D47B8 800D3BB8 46085182 */  mul.s      $f6, $f10, $f8
/* D47BC 800D3BBC 46062281 */  sub.s      $f10, $f4, $f6
/* D47C0 800D3BC0 46005202 */  mul.s      $f8, $f10, $f0
/* D47C4 800D3BC4 44815000 */  mtc1       $at, $f10
/* D47C8 800D3BC8 E6080018 */  swc1       $f8, 0x18($s0)
/* D47CC 800D3BCC C7A40040 */  lwc1       $f4, 0x40($sp)
/* D47D0 800D3BD0 E60C0038 */  swc1       $f12, 0x38($s0)
/* D47D4 800D3BD4 E60C000C */  swc1       $f12, 0xc($s0)
/* D47D8 800D3BD8 46002187 */  neg.s      $f6, $f4
/* D47DC 800D3BDC E60C001C */  swc1       $f12, 0x1c($s0)
/* D47E0 800D3BE0 E6060028 */  swc1       $f6, 0x28($s0)
/* D47E4 800D3BE4 E60C002C */  swc1       $f12, 0x2c($s0)
/* D47E8 800D3BE8 E60A003C */  swc1       $f10, 0x3c($s0)
/* D47EC 800D3BEC 8FBF001C */  lw         $ra, 0x1c($sp)
.L800D3BF0:
/* D47F0 800D3BF0 8FB00018 */  lw         $s0, 0x18($sp)
/* D47F4 800D3BF4 27BD0030 */  addiu      $sp, $sp, 0x30
/* D47F8 800D3BF8 03E00008 */  jr         $ra
/* D47FC 800D3BFC 00000000 */   nop
