# Name: Kartikeya Sharma

.global matrix_sum

.text

# Registration Assignment
# $a0 ($s0), $a1 ($s1) are two 2D matrices
# $a2 ($s2) is another 2D matrix where
# the sum of the matrices represented
# by $a0 ($s0) and $a1 ($s1) will be stored.
matrix_sum:
    move $s0, $a0 # move $a0 to $s0
	move $s1, $a1 # move $a1 to $s1
	move $s2, $a2 # move $a2 to $s2
	li $t0, 0 # $t0 represents the number of iterations
              # the loop has gone through so far

loop:
	li $t1, 6
	beq $t0, $t1, end # if the loop has iterated 6 times, end the function
	nop

    	lb $t2, 0($s0) # get int of first matrix
    	lb $t3, 0($s1) # get corresponding int of second matrix

    	add $t4, $t2, $t3 # compute the sum
    	sb $t4, 0($s2) # store the sum in corresponding spot
                       # in sum matrix

    	addi $s0, $s0, 4 # increment address of first matrix
        	         # to get next int
    	addi $s1, $s1, 4 # increment address of second matrix
                     	 # to get next int
    	addi $s2, $s2, 4 # increment address of sum matrix
        	         # to store next int
    	addi $t0, $t0, 1 # increment number of iterations
    	j loop # jump to back to the beginning of the loop

end:
	jr $ra
