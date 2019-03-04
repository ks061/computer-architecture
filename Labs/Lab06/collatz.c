/* Kartikeya Sharma
 * Date: February 19, 2019
 * Time: 1 PM
 * Lab 06 - collatz.c
 * compile with: make collatz
 * notes: This program computes the
 *        Collatz sequence lengths for
 *        integers 1 through 100. 
 */

#include <stdio.h>
#define MAX_ITEMS 100

int collatz(int n)
{
    // if n is 1: 1
    // if n is even: n / 2 
    // if n is odd: 3 * n + 1
    // checking for even/oddness in C is a debatable topic:
    // http://stackoverflow.com/questions/160930/how-do-i-check-if-an-integer-is-even-or-odd
    if (n == 1) return 1;
    if (n % 2 == 0) return n / 2;
    if (n % 2 == 1) return 3 * n + 1;
    return -1;
}

int find_length(int n)
{
    // TODO: implement a recursive function to count the number of
    // calls to collatz needed to reach 1 starting with n.
    // Note that you need to *count* the number of calls.
    // If the value of n is greater than 1, the find_length() function
    // would call the collatz function recursively.
    int computed_num = n;
    int count = 0;
    while (computed_num != 1) {
        computed_num = collatz(computed_num);
        count++;
    }
    return count;
}

int main(void)
{
    int i;

    for (i = 1; i < MAX_ITEMS; i ++){
        printf ("%d ==> %d\n", i, find_length(i));
    }

    return 0;
}
