# Name: Kartikeya Sharma

.global add_second

.text

# Registration Assignment
# $t0 is number of seconds, minutes, or hours in the struct
# $t1 temporary variable acting as constant
# $s0 is address of struct being dealt with

add_second:
	move $s0, $a0 # move the address of struct from $a0 to $s0

	lb $t0, 0($s0) # load the number of seconds
    addi $t0, $t0, 1 # increment number of seconds

	li $t1, 60
	beq $t0, $t1, increment_minute # if number of seconds is 60,
                                   # increment the number of minutes
	nop

	sb $t0, 0($s0) # store the number of seconds back into the struct

    j end # jump to end of function call

increment_minute:
	li $t0, 0 # set the number of seconds to 0
    sb $t0, 0($s0) # store the reset value of seconds to the struct
	
	addi $s0, $s0, 4 # increment address of struct by one word

	lb $t0, 0($s0)	# load the number of minutes
    addi $t0, $t0, 1 # increment the value of minutes by 1

	li $t1, 60
	beq $t0, $t1, increment_hour # if number of minutes is 60,
                                # increment the number of hours
	nop

	sb $t0, 0($s0) # store the number of minutes back into the struct
	
    j end # jump to end of function call

increment_hour:
    li $t0, 0 # set the number of minutes to 0
    sb $t0, 0($s0) # store the reset value of minutes to the struct

	addi $s0, $s0, 4 # increment address of struct by one word

	lb $t0, 0($s0) # load the number of hours
    addi $t0, $t0, 1 # increment the value of hours by 1

	sb $t0, 0($s0) # store the number of hours

	li $t1, 24 # if the number of hours is 24, reset the
               # number of hours to 0, and store the reset
               # value of the number of hours to the struct
	bne $t0, $t1, end
	nop
	
	li $t0, 0
    sb $t0, 0($s0)
	
end:
	jr $ra
