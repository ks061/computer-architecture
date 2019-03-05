/* Kartikeya Sharma
 * February 26, 2019 at 1 PM
 * lab 07 - counte.c
 * compile with: make counte
 * notes: This file counts the number of e's
 *        in the string.
 */

#include <stdio.h>

extern int counte(char*);

int main(void) {
    // char* string = NULL;
    printf("Enter a string: ");
    // scanf("%s", string);
    char* string = "hellococo";
    printf("There are %d e's\n", counte(string));
    
    return 0;
}

