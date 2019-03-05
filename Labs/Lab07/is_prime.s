# Name: Kartikeya Sharma

.global is_prime

.text

is_prime:
    li $s0, 2
    div $zero, $a0, $s0
    mflo $s1 # $s1 = n, which is stored in $a0, divided by 2

loop:
	bgt $s0, $s1, is_prime # if i > n/2, then n is prime
	nop

	div $zero, $a0, $s0 # hi = n mod i
	mfhi $t0 # n mod i into $t0
	beq $t1, $zero, not_prime # if n mod i is 0, then n is not prime
	nop

	addi $s0, $s0, 1 # increment i
    j loop # go back to start of loop

is_prime:
	addi $v0, $zero, 1 # because n is prime, return 1
    jr $ra

not_prime:
	add $v0, $zero, $zero # because n is not prime, return 0
	jr $ra
	
