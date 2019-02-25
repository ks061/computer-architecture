#  Kartikeya Sharma
#  February 12, 2019 @ 1 PM
#  lab 05 - sumsquares.s
#  notes: This assembly code file
#         contains instructions equivalent
#         to the squares.c program given in
#         Exercise 1 of the lab.
#

.data
    squares: .space 3200 # allocate 3200 bits for int squares[100]
    sum: .space 32 # allocate 32 bits for int sum
    i: .space 32 # allocate 32 bits for int i

    str1: .asciiz "squares["
    str2: .asciiz "]= "
    str3: .asciiz "sum of squares from 0 to 99 = "
    newline: .asciiz "\n"

.text 
main:
    sw $zero, sum # initialize int sum to 0
    sw $zero, i # initialize int i to 0

    calc_squares:
        lw $t0, i # $t0 = i (index in array)
        slti $t1, $t0, 100 # $t1 = 1 if $t0 < 100; else $t1 = 0
        beq $t1, $zero, initi  # continue calculating squares
                               # if the index i is less than 100

        mult $t0, $t0 # lo = i * i (square of index)
        mflo $t2 # $t2 = lo = i * i (square of index)
        sll $t3, $t0, 5 # t3 = $t0 << 5 (memory offset)
        sw $t2, squares($t3) # squares[i] = i * i (set square in array)
        lw $t4, sum # $t4 = sum
        add $t4, $t4, $t2 # sum = sum + squares[i]
        sw $t4, sum # store value in $t4 to sum
        
        addi $t0, $t0, 1 # $t0 = $t0 + 1
        sw $t0, i # store value in $t0 to i
       
        j calc_squares # loop back to beginning of while loop

    initi: sw $zero, i # initialize int i to 0

    print_squares:
        lw $t0, i # $t0 = i (index of array)
        slti $t1, $t0, 100 # $t1 = 1 if $t0 < 100; else $t1 = 0
        beq $t1, $zero, print_sum  # continue calculating squares
                                   # if the index i is less than 100
        
        li $v0, 4 # load in print string syscall code
        la $a0, str1 # load address of string to be printed
        syscall # make syscall

        li $v0, 1 # load in print int syscall code
        add $a0, $t0, $zero # $a0 = $t0 = i
        syscall # make syscall

        li $v0, 4 # load in print string syscall code
        la $a0, str2 # load address of string to be printed
        syscall # make syscall

        li $v0, 1 # load in print int syscall code
        sll $t2, $t0, 5 # t2 = $t0 << 5 (memory offset)
        lw $a0, squares($t2) # get squares[i] into $a0
        syscall # make syscall 

        li $v0, 4 # load in print string syscall code
        la $a0, newline # load address of string to be printed
        syscall # make syscall

        addi $t0, $t0, 1 # $t0 = $t0 + 1
        sw $t0, i # store value in $t0 to i

        j print_squares

    print_sum: 
        li $v0, 4 # load in print string syscall code
        la $a0, str3 # load address of string to be printed
        syscall # make syscall

        li $v0, 1 # load in print int syscall code
        lw $a0, sum # load sum of squares
        syscall # make syscall

        li $v0, 4 # load in print string syscall code
        la $a0, newline # load address of string to be printed
        syscall # make syscall
