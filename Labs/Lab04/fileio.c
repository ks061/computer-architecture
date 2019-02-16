/* Kartikeya Sharma
 * February 5, 2019 @ 1 PM
 * lab 04 - fileio.c
 * compile with: make fileio
 * notes: This file contains 
 *        read_file_bytes(), which
 *        aids reading bytes from
 *        a file. 
 */

#include "fileio.h"

/*
 * Reads byte data from a file and append a null terminator (byte value 
 * of zero, 0).
 *
 *  filename: full path and filename to read from.
 *  bytes: maximum number of bytes to read.
 *  buffer: where to put the read data (note need bytes+1!).
 *  Return value: number of bytes read or -1 on error.
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
