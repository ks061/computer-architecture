# Name: Kartikeya Sharma

.global counte

.text
## Register Assignment
# $t0 - loaded byte
# $t1 - value of 'e'
# $t2 - address of byte being loaded
# $t3 - value of '\0'
# $t4 - number of e's
# $v0 - number of e's (return value)
counte:
	move $t2, $a0 # $t2 contains the address of string[0]
	
        add $t4, $zero, $zero # init $t4 (number of e's in the string)
        li $t1, 'e'
        li $t3, '\0'
loop:
	lb $t0, 0($t2) # load the character referred to by $t2 into $t0
	
	beq $t0, $t3, end       # if character read is the null terminator
                                # end the function
	nop
	
	beq $t0, $t1, increment # if the character read is 'e',
                                # increment the count $v0
	nop

	addi $t2, $t2, 1 # increment the address of the character being read in
    	j loop # jump back to the beginning of the loop

increment:
	addi $t4, $t4, 1 # increment the number of e's in $t4
	addi $t2, $t2, 1 # increment the address to the next character
	j loop # jump back to the beginning of the loop

end:
	add $v0, $t4, $zero # load result into $v0
	jr $ra
