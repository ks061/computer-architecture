# Kartikeya Sharma
# February 19, 2019 - 1:00 PM
# lab 06 - collatz.s
# compile with: none 
# notes: This program converts collatz.c
#        into an analogous program
#        in assembly.

.data
arrow: .asciiz " ==> "
newline: .asciiz "\n"
num_items: .word 100

# Register Assignment
# $v0 - for returning output of find_length; for setting mode of syscalls
# $v1 - for returning output of collatz
# $a0 - for loading arguments for print syscalls
# $a1 - num_items
# $a2 - represents variable i (number whose collatz sequence is being analyzed)
# $a3 - represents variable n (aids in generating collatz sequence within
#       of find_length(i) and collatz(n))
# $t0 - aids in bitwise AND operation
# $t1 - temporary used for integers (multi-purpose)
# $s0 - holds result of find_length(i)

.text
init:
	la $a1, num_items	# load address of num_items into $a1
	lw $a1, 0($a1)          # $a1 = num_items
	addi $a2, $zero, 1 	# i = 1
	
main:
	beq $a2, $a1, end	# end the loop if i == num_items
	
	move $a3, $a2           # n = i
	add  $v0, $zero, $zero
	jal find_length 	# get find_length(i) 
	move $s0, $v0           # move return value of find_length(i) to $s0
	
	move $a0, $a2           
	addi $v0, $zero, 1	
	syscall                 # print i
	
	la $a0, arrow           
	addi $v0, $zero, 4	
	syscall                 # make syscall to print "==>"
	
	move $a0, $s0           
	addi $v0, $zero, 1	
	syscall                 # print return value of find_length(i)
	
	la $a0, newline		
	addi $v0, $zero, 4      
	syscall                 # print new line
	
	addi $a2, $a2, 1	# increment i
	j main			# jump back to the start of the loop
	
find_length:
	addi $t1, $zero, 1	
	beq $t1, $a3, length_one # return 1 if n == 1 
	
	sw $ra, 0($sp)          # store return address in stack
	jal collatz             # call collatz(n)
	lw $ra, 0($sp)          # load return address from stack
	move $a3, $v1		# n = collatz(n)
	addi $v0, $v0, 1	# return find_length(n) + 1
	j find_length           # call find_length(i)

length_one:
	addi $v0, $v0, 1	# return 1
	jr $ra                  # jump to calee find_length(i)
		
collatz:
	addi $t1, $zero, 1
	beq $a3, $t1, base_case	# if n == 1, return 1
	andi $t0, $a3, 1	# check if even by anding n with 1
	beqz $t0, n_is_even	# if n is even, return n/2
	
	addi $t1, $zero, 3      
	mul $v1, $t1, $a3       
	addi $v1, $v1, 1	# otherwise, if n is odd, return 3 * n + 1
	jr $ra	

base_case:
	addi $v1, $zero, 1	# return 1
	jr $ra

n_is_even:
	addi $t1, $zero, 2
	div $v1, $a3, $t1	# returns n/2
	jr $ra                  

end:
	addi $v0, $zero, 10     # loads the exit syscall code into $v0
	syscall                 # makes the syscall to exit
