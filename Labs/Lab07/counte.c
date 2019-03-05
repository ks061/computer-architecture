/* Kartikeya Sharma
 * February 26, 2019 at 1 PM
 * lab 07 - counte.c
 * compile with: make counte
 * notes: This file counts the number of e's
 *        in the string.
 */

#include <stdio.h>
#define MAX_CHARS 200

extern int counte(char*);

int main(void) {
    char input_string[MAX_CHARS];
    printf("Enter a string: ");
    fgets(input_string, MAX_CHARS, stdin);
    printf("There are %d e's\n", counte(input_string));
    
    return 0;
}

