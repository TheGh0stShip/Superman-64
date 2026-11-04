.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

glabel func_800C2AB0
/* C36B0 800C2AB0 AFA40000 */  sw         $a0, ($sp)
/* C36B4 800C2AB4 AFA60008 */  sw         $a2, 8($sp)
/* C36B8 800C2AB8 03E00008 */  jr         $ra
/* C36BC 800C2ABC A4A60016 */   sh        $a2, 0x16($a1)
