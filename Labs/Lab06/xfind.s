# CSCI 206 Computer Organization & Programming
# Date: 2011-09-19
# Copyright (c) 2011 Bucknell University
#
# Permission is hereby granted, free of charge, to any individual or
# institution obtaining a copy of this software and associated
# documentation files (the "Software"), to use, copy, modify, and
# distribute without restriction, provided that this copyright and
# permission notice is maintained, intact, in all copies and
# supporting
# documentation.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
# KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
# WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL BUCKNELL UNIVERSITY BE LIABLE FOR ANY
# CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
# THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
#
# Student name: Kartikeya Sharma
#
#
# This program uses a procedure xfind to find a particular character.
# See detailed instructions in lab handout

	.data
# Define constants here

	.align 2

# These are the two test strings, use one at a time
string: .asciiz "Where is my xbox 360?"
# string: .asciiz "None of that character in here."

x:      .byte 'x'

	.text

main:
        # Prepare for procedure call
	addi	$sp, $sp, -4		# saving registers
	sw	$ra, 0($sp)
	
	la	$a0, string		# load address of string
	jal	xfind			# call function convert

	add $a0, $v0, $zero		# set the argument of the syscall
                            		# to be the return value of the
                            		# xfind function                     		
	addi $v0, $zero, 34		# syscall code to print hexadecimal
                            		# values (format of memory address)
	syscall 			# make syscall

	lw	$ra, 0($sp)		# restoring registers
	addi	$sp, $sp, 4
	
	li	$v0, 10			# exit to OS
	syscall

# write the code of function xfind after this comment
# 
# Algorithm
# copy starting memory address from $a0 into $t0
# load x byte into $t1
# loop:
# 	load byte from address $t0 into $t2
#       if $t1 is 0 (read in null terminator):
# 		load -1 into $v0
# 		jump to end_loop
# 	
# 	if $t1 == $t2:
# 		load $t0 into $v0
#               jump to end_loop
# 	increment the memory address $t0 by 1
# 	jump to loop
# end_loop:
#       jr $ra
# 
# Assignment
# $a0 – The starting memory address of the string.
#       This address will be placed in the register
#        by the main program which calls your procedure.
# $v0 – The result (a valid address or the constant -1).
# $ra – The return address for the procedure.
#       The instruction jr $ra will use to go back to
#       the caller with
# $t0 - The address from where a byte is being read
# $t1 - The value of the 'x' byte
# $t2 - The value of the byte being read in 
xfind:
	add $t0, $a0, $zero # load the starting address of the string into $t0
        lb $t1, x($zero) # load the value of 'x' into $t1
        
        loop: # looping through bytes
                lb $t2, 0($t0) # load the byte being read in
                
                
                bne $t2, $zero, check_byte # if the byte read is not a null 
                			   # character continue with checking the byte
                addi $v0, $zero, -1 # if the byte read in is a null character
                		    # set the return value to -1
                j end_loop # jump to after the end of the loop
		
		
		check_byte: bne $t1, $t2, increment # if the byte read in is not x, continue
						    # with incrementing the memory address by 1
		add $v0, $t0, $zero # if the byte read in is x, set  the return value to the 
				    # memory address of the byte
		j end_loop # jump to after the end of the loop


		increment: addi $t0, $t0, 1 # increment the memory address of the byte
					    # being read by 1
		j loop # loop back to the start of the loop
	end_loop: 
	
		jr $ra # jump to the return address in $ra
		
