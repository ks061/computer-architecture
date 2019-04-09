   0x00400710 <+0>:	addiu	sp,sp,-40
   0x00400714 <+4>:	sw	ra,36(sp)
   0x00400718 <+8>:	sw	zero,24(sp)
   0x0040071c <+12>:	lui	a0,0x40
   0x00400720 <+16>:	addiu	a0,a0,2396
   0x00400724 <+20>:	jal	0x4005a0 <printf@plt>
   0x00400728 <+24>:	move	at,at
   0x0040072c <+28>:	lui	a0,0x40
   0x00400730 <+32>:	addiu	a0,a0,2412
   0x00400734 <+36>:	addiu	a1,sp,24
   0x00400738 <+40>:	jal	0x4005d0 <__isoc99_scanf@plt>
   0x0040073c <+44>:	move	at,at
   0x00400740 <+48>:	li	v1,1
   0x00400744 <+52>:	beq	v0,v1,0x400768 <main+88>
   0x00400748 <+56>:	lw	a0,24(sp)
   0x0040074c <+60>:	lui	a0,0x40
   0x00400750 <+64>:	addiu	a0,a0,2416
   0x00400754 <+68>:	jal	0x4005b0 <puts@plt>
   0x00400758 <+72>:	move	at,at
   0x0040075c <+76>:	li	a0,1
   0x00400760 <+80>:	jal	0x4005c0 <exit@plt>
   0x00400764 <+84>:	move	at,at
   0x00400768 <+88>:	jal	0x4007bc <check_pin>
   0x0040076c <+92>:	move	at,at
   0x00400770 <+96>:	beqz	v0,0x400790 <main+128>
   0x00400774 <+100>:	lui	a0,0x40
   0x00400778 <+104>:	lui	a0,0x40
   0x0040077c <+108>:	addiu	a0,a0,2432
   0x00400780 <+112>:	jal	0x4005b0 <puts@plt>
   0x00400784 <+116>:	move	at,at
   0x00400788 <+120>:	j	0x4007a0 <main+144>
   0x0040078c <+124>:	li	v0,-99
   0x00400790 <+128>:	addiu	a0,a0,2444
   0x00400794 <+132>:	jal	0x4005b0 <puts@plt>
   0x00400798 <+136>:	move	at,at
   0x0040079c <+140>:	move	v0,zero
   0x004007a0 <+144>:	lw	ra,36(sp)
   0x004007a4 <+148>:	jr	ra
   0x004007a8 <+152>:	addiu	sp,sp,40
