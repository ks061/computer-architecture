/* Kartikeya Sharma
 * Date: January 22, 2019
 * Time: 1 PM
 * lab 02 - isalary.c
 * compile with: make fsalary
 * notes: none
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
