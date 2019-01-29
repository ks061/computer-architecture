/* Kartikeya Sharma
 * Date: January 22, 2019
 * Section: CSCI206L - 61
 * Time: 1 PM
 * lab 02 - primefact.c
 * compile with: make primefact
 * notes: none
 * 
 * Output:
 *
 * [ks061@brki164-lnx-25 Lab02]$ time python primefact.py
 * 5
 * 19
 * 22605091
 *
 * real	0m2.537s
 * user	0m2.482s
 * sys	0m0.011s
 * [ks061@brki164-lnx-25 Lab02]$ time ./primefact
 * 5
 * 19
 * 22605091
 *
 * real	0m0.053s
 * user	0m0.051s
 * sys	0m0.001s
 *
 * Results Discussion:
 *
 * As shown above, running the command ./primefact (running
 * the compiled version of primefact.c) took significantly
 * less time (more than a factor of 10) in running than
 * did running the command python primefact.py across all
 * time metrics provided by the Linux command time, including
 * real time between invocation and termination ("real"), 
 * the user CPU time ("user"), and the system CPU time ("sys").
 */
#include <stdio.h>

int main(void) {
	int n = 2147483645;
	int i = 2;

	while (i<=n) {

		if (n % i == 0) {
			printf("%d\n",i);
			n = n / i;
			i -= 1;
		}

		i+=1;
	}

	return 0;
}
