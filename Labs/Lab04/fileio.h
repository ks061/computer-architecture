/* Kartikeya Sharma
 * February 5, 2019 @ 1 PM
 * lab 04 - fileio.h
 * notes: This header file contains 
 *        the method definitions for 
 *        methods in fileio.c.
 */

// Header guards; only define
// methods if not already defined
#ifndef __fileio_h_
#define __fileio_h_

// for O_RDONLY, etc.
// Inclusion of system libraries
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of bytes
// that will be read onto
// the screen
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
int read_file_bytes(char* filename, int bytes, char* buffer);

#endif
