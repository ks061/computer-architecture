/* Kartikeya Sharma
 * February 5, 2019 @ 1 PM
 * lab 04 - head2.c
 * compile with: make head2
 * notes: This program acts similarly 
 *        to the head command.
 */

#include "fileio.h"

/*
 * Coordinates reading a particular number of bytes (default: 10)
 * from a file; exits with an error if unsuccessful
 *
 * argc: number of command line arguments inputted
 * argv: array of command line arguments inputted
 * Return value: 0 if the program runs successfully (without error)
 */
int main(int argc, char* argv[])
{
    int readbytes = 10;         // default to 10 bytes
    char buffer[MAXBYTES+1];    // buffer to hold file data

    if (argc < 2){
        // missing required argument
        printf("Usage %s <filename> [<bytes>]\n", 
                argv[0]);
        exit(-1);
    }
    if (argc > 2){
        // process optional bytes argument
        readbytes = atoi(argv[2]);
        if (readbytes > MAXBYTES){            
            printf("bytes is too large, max supported value is %d!\n",
                    MAXBYTES);
            exit(-2);
        }
    }
    if (read_file_bytes(argv[1], readbytes, buffer) >= 0){
        printf("%s\n", buffer);
    } else {
        printf("Error: could not read file!\n");
        exit(-3);
    }
    return 0;
}
