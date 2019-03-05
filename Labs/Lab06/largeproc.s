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
# This program demonstrates passing a large number of arguments to a
# procedure which is not a leaf procedure.

	.data
	.align 2
A:	.word 3
B:	.word 7
C:	.word 4
D:	.word 9
E:	.word 3
F:	.word 8
Result1:.word 0xDEADBEEF
Result2:.word 0xDEADBEEF
newline:.asciiz "\n"

	.text

# Register Documentation
# $a0 - address and word of label A
# $a1 - address and word of label B
# $a2 - address and word of label C
# $a3 - address and word of label D
# $t0 - address of E, value of E
# $t1 - address of F, value of F
# $t2 - stores the address of Result1
# $t3 - stores the address of Result2
# $v0 - stores value of Result1
# $v1 - stores value of Result2

# The main() procedure calls largeProc, storing the results into
# Result1 and Result2 and also printing them out to the terminal.
main:

# Prepare arguments to pass to largeProc
    la 	$t0, E 		    # load address of E into $t0
    lw	$t0, 0($t0)     # load word of label E from its address in $t0 into $t0
    addi $sp, $sp, -4   # decrement the stack pointer address by a word
    sw 	$t0, 0($sp)     ## goal: store word of label E at stack pointer address
	
    la  $t1, F		    # load address of F into $t1
    lw	$t1, 0($t1)     # load word of label F from its address in $t1 into $t1
    addi $sp, $sp, -4   # decrement the stack pointer address by a word
    sw	$t1, 0($sp)     ## goal: store word of label F at stack pointer address
	
    la  $a0, A		    # load address of A into $a0
    lw	$a0, 0($a0)     ## goal: load word of label A from its address in $a0 into $a0
    la	$a1, B          # load address of B into $a1
    lw	$a1, 0($a1)     ## goal: load word of label B from its address in $a1 into $a1
    la	$a2, C          # load address of C into $a2
    lw	$a2, 0($a2)     ## goal: load word of label C from its address in $a2 into $a2
    la	$a3, D          # load address of D into $a3
    lw	$a3, 0($a3)     ## goal: load word of label D from its address in $a3 into $a3
	
# Call largeProc
    jal largeProc       # call the largeProc function

# Print the results returned from largeProc
    sw	$v0, Result1($zero)     # store first returned value ($v0) into address of label Result1
    sw	$v1, Result2($zero)     # store second returned value ($v1) into address of label Result2
	
    move $a0, $v0       # move first returned value ($v0) into $a0
    addi $v0, $zero, 1  # load syscall code for print int into $v0
    syscall             # make syscall (print first returned value in $v0)
	
    la 	$a0, newline    # load address of where the new line string is into $a0
    addi $v0, $zero, 4  # load syscall code for print string into $v0
    syscall             # make syscall (print new line)
	
    move $a0, $v1	# move second returned value ($v1) into $a0
    addi $v0, $zero, 1  # load syscall code for print int into $v0
    syscall             # make syscall (print second returned value in $v1)

# The program is finished. Terminate the execution.
    addi $v0, $zero, 10	# system call for exit
    syscall             # make syscall to exit

# This large complicated procedure takes 6 paramters and returns 2.
# Additionally this procedure calls another procedure.
# It is assumed that $fp has been set correctly

largeProc:
	
# Store registers which must be saved onto the stack
    lw	$t1, 0($sp)    # load F from stack into $t1
    addi $sp, $sp, 4   # increment stack pointer by a word
    lw	$t0, 0($sp)    # load E from stack into $t0

# Compute the first result
    add $v0, $a1, $a2   # $v0 = p1 + p2
    add $v0, $v0, $t0   # $v0 = (p1 + p2) + p4

# Compute the second result
    sub $v1, $a0, $a3   # $v1 = p0 - p3
    add	$v1, $v1, $t1   # $v1 = (p0 - p3) + p5

# Call smallProc for the heck of it, but save $v0,
# and $v1 because smallProc could possibly overwrite them!
    sw	$v0, 0($sp) 	# store large_result.1 into the stack
	
    addi $sp, $sp, -4   # decrement stack pointer by a word
    sw	$v1, 0($sp)     # store large_result.2 into the stack
	
    addi $sp, $sp, -4   # decrement stack pointer by a word
    sw $ra, 0($sp)      # store return address to the stack
	
    jal	smallProc       # jumps to the label smallProc and
                        # and updates $ra appropriately
                
# Restore registers using the stack
    lw	$ra, 0($sp)     # load return address to original $ra
	
    addi $sp, $sp, 4    # increment stack pointer by a word
    lw	$v1, 0($sp)     # load large_result.2 into $v1
	
    addi $sp, $sp, 4    # increment stack pointer by a word
    lw	$v0, 0($sp)     # load large_result.1 into $v0
	
    jr	$ra             # jump back to the return address

# This procedure computes nothing useful, it just returns.
smallProc:

    jr	$ra             # jump to the return address
	
# If I had to return three-word sized integer values, I would save two of the values in $v0 and $v1.
# Then, I would save the 3rd value in the stack.
