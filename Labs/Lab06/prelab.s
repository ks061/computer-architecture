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
# This simple program demonstrates writing very simple leaf procedures.
# The program computes an expression in the form of "4x - (2y + c)".
# You are to call the procedure "my_func", taking two parameters (x and y) and
# produce "4x - (2y + c)" within the procedure.

	.data
	.align 2
# Define the constant c here
C:	.word	1

	.text

main:
	# Call my_func(2, 3)
	addi	$a0, $zero, 2
	addi	$a1, $zero, 3
	jal	my_func
	add	$s0, $zero, $v0		# save result in $s0

	# Call my_func(5, 6)
	addi	$a0, $zero, 5
	addi	$a1, $zero, 6
	jal	my_func
	add	$s1, $zero, $v0     # save result in $s1

        add $s1, $s1, $s0 # $s1 = my_func(2, 3) + my_func(5, 6)
        
        addi $v0, $zero, 1 # syscall code for print int
        add $a0, $s1, $zero # $a0 = my_func(2, 3) + my_func(5, 6)
        syscall # make syscall

	addi	$v0, $zero, 10				# system call for exit
	syscall

# my_func = 4x - (2y + 1)
my_func:
	addi $t0, $zero, 2 # $t0 = 2
        mult $t0, $a1 # lo = 2y
        mflo $t0 # $t0 = lo = 2y
        lw $t1, C # load C into $t1
        add $t0, $t0, $t1 # $t0 = 2y + C

        addi $t2, $zero, 4 # $t2 = 4
        mult $t2, $a0 # lo = 4x
        mflo $t2 # $t2 = lo = 4x
        
        sub $v0, $t2, $t0 # $t2 = 4x - (2y + C)
        
        jr $ra

## $ra values
## 0x0040000c (corresponds to line #42, which is the 4th instruction in the text segment)
## 0x0040001c (corresponds to line #48, which is the 8th instruction in the text segment)
