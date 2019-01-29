/* Kartikeya Sharma
 * Date: January 22, 2019
 * Time: 1 PM
 * lab 02 - isalary.c
 * compile with: make isalary
 * notes: This program takes in an hourly
 * 	  wage as an integer and returns
 * 	  the annual salary of an employee.
 * 	  This assumes a 40 hour work week.
 */

#include <stdio.h>
 
int main(void) {
   int hourlyWage;
   printf("Enter hourly wage (integer): ");
   scanf("%d", &hourlyWage);
 
   printf("Annual salary is: ");
   printf("%d", hourlyWage * 40 * 50);
   printf("\n");
 
   return 0;
}
