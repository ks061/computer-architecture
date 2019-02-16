/* Kartikeya Sharma
 * February 5, 2019 @ 1 PM
 * lab 04 - head.c
 * compile with: make head
 * notes: This program acts similarly 
 *        to the head command.
 */


// for O_RDONLY, etc.
#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBYTES 1024

/*
 * Reads byte data from a file and append a null terminator (byte value 
 * of zero, 0).
 *
 * filename: full path and filename to read from.
 * bytes: maximum number of bytes to read.
 * buffer: where to put the read data (note need bytes+1!).
 * Return value: number of bytes read or -1 on error.
 */
int read_file_bytes (char* filename, int bytes, char* buffer)
{
    int file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor < 0) {
        printf("%s could not be opened.", filename);
        return -1;
    }

    int bytes_read = read(file_descriptor, buffer, bytes);
    if (bytes_read < 0) {
        printf("%s could not be read.", filename);
        return -1;
    }
    buffer[bytes] = '\0';
    
    int close_status = close(file_descriptor);
    if (close_status < 0) {
        printf("%s could not be closed.", filename);
        return -1;
    }
    
    return 0;
}

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
