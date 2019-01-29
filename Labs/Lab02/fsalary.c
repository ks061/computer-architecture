/* Kartikeya Sharma
 * Date: January 22, 2019
 * Section: CSCI206L - 61
 * Time: 1 PM
 * lab 02 - fsalary.c
 * compile with: make fsalary
 * notes: This program takes in an hourly wage
 *        and the number of weeks worked to derive
 *        the annual salary for an employee.
 *        This assumes a 40 hour work week.
 */

#include <stdio.h>
 
int main(void) {
   float hourlyWage;
   printf("Enter hourly wage (floating point): ");
   scanf("%f", &hourlyWage);

   int weeksWorked;
   printf("Enter weeks worked (integer): ");
   scanf("%d", &weeksWorked);

   printf("Annual salary is: $");
   printf("%.2f", hourlyWage * 40 * weeksWorked);
   printf("\n");
 
   return 0;
}
