/* Kartikeya Sharma
 * Date: January 22, 2019
 * Time: 1 PM
 * lab 02 - salary.c
 * compile with: make salary
 * notes: The goal of this program
 * 	  is to compute the annual
 * 	  wage of a person given
 * 	  a 40 hour work week and 
 * 	  $20 hourly wage.
 */

#include <stdio.h>
 
int main(void) {
   int hourlyWage = 20;
 
   printf("Annual salary is: ");
   printf("%d", hourlyWage * 40 * 50);
   printf("\n");
 
   return 0;
}
