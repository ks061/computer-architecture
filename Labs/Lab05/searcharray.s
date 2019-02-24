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
# data segment -------------------------------------
.data	 
.align 2
 
save:
.word 0,0,0,0,7,0,0,0,0,0 	# array save[.]
ivar:
.word 0 			# int i
kvar:
.word 0 			# int k
donestring:
.asciiz "loop terminated, i= "
promptstring:
.asciiz "Enter the value to search for: "
valnotfoundstring:
.asciiz "value not found"
# code segment --------------------------------------
.text
init:
	li 	$s3, 0 		# store 0 in i
	sw 	$s3, ivar
	li 	$s5, 7 		# store 7 in k
	sw 	$s5, kvar
        la 	$s4, save 	# put the address of save[0] in $s4

        la      $a0, promptstring
        li      $v0, 4
        syscall # print prompt string

        li      $v0, 5
        syscall # read integer
        add      $t0, $v0, $zero # store read integer in t0
        
test:
	# reserve $t1 for byte offset of save array
	add	$t1, $zero, $s3 	# $t1 = i
	sll	$t1, $t1, 2 		# cnvert index to byte addres (multiply $t1 by 4)
	add	$t1, $t1, $s4		# $t1 = &save[0] + $t1 (byte address of save[i])
	lw	$t2, 0($t1)		# $t2 = save[i]
	
        beq	$t2, $t0, terminate
	addi	$s3, $s3, 1
        slti    $t3, $s3, 10            # ensure that index < 10
        beq     $t3, $zero, endofarray 
	j	test
	 
terminate:
	la	$a0, donestring
	li	$v0, 4
	syscall
	
	add	$a0, $zero, $s3		# print value of i
	li	$v0, 1
	syscall
	
	j exit

endofarray:
        la      $a0, valnotfoundstring
	li      $v0, 4
        syscall

exit:	    
	li 	$v0, 10 		# terminate program
	syscall	
	
