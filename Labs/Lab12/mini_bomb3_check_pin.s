   0x004007b0 <+0>:	xor    %al,0x2245500(%ebx)
   0x004007b6 <+6>:	add    %al,0x14(%ecx)
   0x004007b9 <+9>:	bound  %eax,(%eax)
   0x004007bb <+11>:	add    (%eax),%edi
   0x004007bd <+13>:	test   %al,(%eax)
   0x004007bf <+15>:	inc    %ecx
   0x004007c0 <+16>:	add    %eax,%esp
   0x004007c2 <+18>:	add    %cl,(%eax)
   0x004007c4 <+20>:	add    %al,(%eax,%edx,1)
   0x004007c7 <+23>:	sub    (%ebx),%eax
   0x004007c9 <+25>:	loopne 0x4007cb <check_pin+27>
   0x004007cb <+27>:	or     %al,(%eax)
   0x004007cd <+29>:	add    %dl,(%eax)
   0x004007cf <+31>:	and    %eax,(%ebx)
