/* Kartikeya Sharma
 * February 5, 2019 @ 1 PM
 * lab 04 - fileio.c
 * compile with: make fileio
 * notes: This file contains 
 *        file input/output methods,
 *        which aid in reading/
 *        writing data from/to
 *        a file. 
 */

#include "fileio.h"
#include "string.h"

/*
 * Reads byte data from a file and appends a null terminator (byte value 
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
 * Reads lines of data from a file and appends a null terminator (byte 
 * value of zero, 0).
 *
 * file_descriptor: file descriptor referring to the file
 *                  to be read
 * buffer: where to put the read data
 * Return value: number of lines read or -1 on error (failure to close).
 */
int read_file_lines(int file_descriptor, char buffer[MAXLINES][MAXBYTES+1])
{
    FILE *file_pointer = fdopen(file_descriptor, "r");
    int num_lines_read = 0;
    while ((fgets(buffer[num_lines_read], MAXBYTES+1, file_pointer) != NULL)\
           && (num_lines_read < MAXLINES)) {
        printf("string length: %d\n",strlen(buffer[num_lines_read]));
    	num_lines_read++;
    }

    int close_status = fclose(file_pointer);
    if (close_status < 0) {
    	return -1;
    }
    
    return num_lines_read;
}
