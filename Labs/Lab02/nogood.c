/* nogood.c -- a program with errors
 * Stephen Prata - C Primer Plus 6/e - Listing 2.4
 * compile with: make nogood
 *
 * Kartikeya Sharma (modified by; not author)
 * Date: January 22, 2019
 * Section: CSCI206L - 61
 * Time: 1 PM
 * lab 02 - nogood.c
 * compile with: make nogood
 * notes: This program calculates the square and cube
 * 	  of n; the goal of this program is to
 * 	  learn how to debug errors in C.
 */ 
#include <stdio.h>
int main(void) {
	int n, n2, n3;

	n = 5;
	n2 = n * n;
	n3 = n2 * n;

	printf("n = %d, n squared = %d, n cubed = %d\n", n, n2, n3);

	return 0;
}
