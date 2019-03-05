/* Kartikeya Sharma
 * February 26, 2019 at 1 PM
 * lab 07 - time.c
 * compile with: make time
 * notes: This program increments a time value.
 */

#include <stdio.h>
#include <time.h>
 
extern void add_second(struct tm *ptr);

int main(void)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
 
    printf ("it is now: %s\n", asctime(tm));

    int i;
    for (i = 0; i < 2345; i++) {
        add_second(tm);
    }
     
    printf ("it is now: %s\n", asctime(tm));
    
    return 0;
}
