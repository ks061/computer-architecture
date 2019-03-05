# Name: Kartikeya Sharma

.global counte

.text

counte:
	move $s0, $a0 # $s0 contains the address of string[0]
	add $v0, $zero, $zero # set $v0 (number of e's in the string)

loop:
	lb $t0, 0($s0) # load the character referred to by $s0 into $t0

	beq $t0, 'e', increment # if the character read is 'e',
                            # increment the count $v0
	nop

	beq $t0, '\0', end      # if character read is the null terminator
                            # end the function
	nop

	addi $s0, $s0, 1 # increment the address of the character being read in
    j loop # jump back to the beginning of the loop

increment:
	addi $v0, $v0, 1 # increment the number of e's in $v0
	addi $s0, $s0, 1 # increment the address to the next character
	j loop # jump back to the beginning of the loop

end:
	jr $ra
