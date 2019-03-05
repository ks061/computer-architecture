/* Kartikeya Sharma
 * February 26, 2019 @ 1 PM
 * lab07 - primes.c
 * compile with: gcc -Wall primes.c -o primes
 * notes: This program brute force
 *        guesses prime numbers.
 */

// real = 61.064 seconds
// user = 50.680 seconds
// sys = 8.340 seconds

#include <stdio.h> 

#define MAX 10020

extern int is_prime(int);

int main (void)
{
    int i, n = 0;

    for (i = 2; n < MAX; i++){
        if (is_prime(i)){
            if ((n % 10) == 0){
                printf("\n");
            }
            printf("%7d", i);
            n++;
        }
    }
    printf("\n");

    return 0;
}
