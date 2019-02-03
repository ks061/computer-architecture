
# CSCI 206 Computer Organization & Programming
# Date: 2011-08-29
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

# The purpose of this program is to store the result of the sum of the first ten positive
# integers in memory.


	.data # Signals that variable declarations follow this line.
	      # This is done because separation of variable declarations and instructions
	      # allows the assmebler to distinguish these two categories of program
	      # statements.
	
unused:	.word 0xDEADBEEF # Stores the hexadecimal 0xDEADBEEF as a 32 bit word in RAM
                         # (random access memory)
                         # This is done because this 32 bit word can now be accessed from the 
			 # data segment later in the program.
				
x:	.word 89 # Stores the decimal 89 as a 32 bit word in RAM (random access memory)
		 # This is done because this 32 bit word can now be accessed from the 
		 # data segment later in the program.			
						
	.text # Signals that instructions follow this line.
	      # This is done because separation of variable declarations and instructions
	      # allows the assmebler to distinguish these two categories of program
	      # statements.
main:						# The label main signals the start of
						# the program. The purpose of placing
						# this label is to tell the simulator
						# where to start the program.

	
	add		$t0, $zero, $zero  	# This line adds the value stored in the zero
						# register to the value stored in the zero
						# register and sets the result to the temporary
						# register $t0. The purpose of this line is to
						# initialize the register $t0 with the value 0
						# before being used by the loop in this program.
	add		$t1, $zero, $zero	# This line adds the value stored in the zero
						# register to the value stored in the zero
						# register and sets the result to the temporary
						# register $t1. The purpose of this line is to
						# initialize the register $t1 with the value 0
						# before being used by the loop in this program.

loop: # This statement marks the beginning of the loop. The purpose of this loop is to store
      # the sum of the first ten positive integers (starting at 1) as the value of register $t0.
	add		$t1, $t1, $t0 # This line adds the value stored in the register $t0 to
				      # that stored in the register $t1 and assigns the resulting
				      # value to register $t1. The purpose of this line is to
				      # increment the register $t1 by the value stored in $t0 at
				      # the start of each loop.
	addi		$t0, $t0, 1 # This line adds the constant value 1 to the value stored in
				    # the register $t0 and assigns the resulting value to register
				    # $t0. The purpose of this line is to increment the value of
				    # the register $t0 by 1.
	ble		$t0, 10, loop # This line directs the program to begin reading instructions
				      # at the label 'loop' if the value in the register $t0 is
				      # less than or equal to 10. The purpose of this line is
				      # to ensure that the value of the register $t0 is greater
				      # than 10 before the program exits the loop.

	la		$t2, x # This line sets the value of $t2 to the address of the label x.
			       # The purpose of setting the value of $t2 to that address is to make
			       # the address accessible in a next instruction (storing word).
	sw		$t1, 0($t2) # This line stores the value of the register $t1 at the address
				    # stored as the value of $t2 (at an offset of 0). The purpose
				    # of this line is to store the value aforeset to the sum
				    # of the first 10 positive integers to memory.
	
	li		$v0, 10			# system call for exit; The purpose of this line
						# is to load the service number 10 to the $vo
						# register, which an instruction 'syscall' will
						# read the service number of 10 in value of the 
						# $v0 register and interpret that the program
						# should exit.
	syscall				# Exit!; The purpose of this line is to make a system call
					# to execute an instruction corresponding to the service
					# number stored in $v0, which, in this case, is 10, 
					# signalling the system to exit the code.

