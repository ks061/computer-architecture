/* Kartikeya Sharma
 * Date: January 22, 2019
 * Time: 1 PM
 * lab 02 - isalary.c
 * compile with: make isalary
 * notes: none
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
