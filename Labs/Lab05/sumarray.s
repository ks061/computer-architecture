# CSCI 206 Computer Organization & Programming
# Date: 2011-09-13
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
# This program calculates the sum of the values in array A and counts
# the number of values in the array.
#
# Similarly to a C-string, the array is terminated by sentinel value
# equal to zero.
#
# The sum is stored in $s0 and the count in $s1

	.data
A:	.word 5 4 3 2 4 1 0	# declare array int A[]={5,4,3,2,4,1,0};
numelemstring: .asciiz "Number of elements = "
sumstring: .asciiz "Summation = "
newline: .asciiz "\n"

	.text	
main:				# This symbols marks the first instruction of your program
        move    $t0, $zero      # initialize t0 (starting index) to 0
arrloop:
        lw      $t1, A($t0)     # load element from array at index
        beq     $t1, $zero, endofarr # end loop if element is 0
        add     $s0, $s0, $t1   # add element to sum s0
        addi    $t0, $t0, 4     # increment index to start of next byte
        j       arrloop         # jump to beginning of array loop
endofarr:
        li      $v0, 4          # load print string syscall code
        la      $a0, numelemstring # load string to print
        syscall                 # make syscall
     
        li      $v0, 1          # load print int syscall code
        srl     $a0, $t0, 2     # convert bit index to byte index
        syscall                 # make syscall

        li      $v0, 4          # load print string syscall code
        la      $a0, newline    # load address of new line string
        syscall                 # make syscall

        li      $v0, 4          # load print string syscall code
        la      $a0, sumstring  # load string to print
        syscall                 # make syscall
     
        li      $v0, 1          # load print int syscall code
        add     $a0, $s0, $zero # load sum
        syscall                 # make syscall     

	li	$v0, 10		# system call for exit
	syscall			# Exit!

