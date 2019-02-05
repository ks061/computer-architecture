/* Name: Kartikeya Sharma
 * Date: January 29, 2019
 * Section: CSCI206L - 61
 * Time: 1 PM
 * lab 03 - c_mystery.c
 * compile with: make c_mystery
 * notes: This program is a translation of the
          assembly language code mystery.asm.
          The general purpose of this program is to
          sum the first ten positive integers and
          store the result in the t1 register.
 */

#include <stdio.h>
int main() 
{
    int unused = 0xDEADBEEF; /* unused variable from MIPS program */

    int x = 89; /* output variable */
    
    int t0 = 0; /* t0 register representation */
    int t1 = 0; /* t1 register representation */

    do {
        t1 = t1 + t0; /* increment value stored
		         in the t1 register representation
                         by the next positive integer
                         (represented by the
                         t0 register representation)
                         in the series of consecutive
                         positive integers */
        t0 += 1; /* increment the value stored by the t0 register 
                    representation, representing the next positive
                    integer to be added to the value stored in the
                    t1 register representation, by 1 */
    } while (10 >= t0); /* sum the first ten positive integers and
                           store the result in the t1 register
                           representation */
    
    x = t1; /* store the aforecalculated sum from the t1
               register representation in x */ 

    return 0; /* exit the program */
}
