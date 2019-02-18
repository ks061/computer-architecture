/* Kartikeya Sharma
 * February 5, 2019 @ 1 PM
 * lab 04 - string_token.c
 * compile with: make string_token
 * notes: This program is a customized
 *        version of the strtok()
 *        function.
 */      

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileio.h"

int
main(int argc, char *argv[])
{
    char *str1, *token;
    char *saveptr1;

    char * delim = " ;=$(){}#+,<>\"[]*'/!%&:\\\n\r\t";

    if (argc !=2) {
        printf("./string_token <file name>");
        exit(EXIT_FAILURE);
    }

    /*
    // Opening the file
    int file_descriptor = open(argv[1], O_RDONLY);
    if (file_descriptor == -1) {
        printf("Error occured while trying to open the file.\
                Please check the inputted file path.");
        exit(-1);
    }
    
    // Declaring string (char array)
    char str[MAXLINES * (MAXBYTES + 1)];

    // Importing 2D array into string (char array)
    int num_line;
    int num_byte;
    int index;
    for (num_line = 0; num_line < MAXLINES; num_line++) {
        for (num_byte = 0; num_byte < MAXBYTES+1; num_byte++) {
            index = num_line * (MAXBYTES + 1) + num_byte;
            str[index] = buffer[num_line][num_byte];
        }
    }
    */
    
    // Opening the file
    FILE *file_pointer = fopen(argv[1], "r");

    if (file_pointer == NULL) {
        printf("File could not be opened.\
                Please check the inputted\
                filepath.");
        exit(EXIT_FAILURE);
    }

    // Reading the file into a buffer
    // and parsing the file for tokens
    char buffer[MAXBYTES+1];
    int count = 1;
    while (fgets(buffer, MAXBYTES+1, file_pointer) != NULL) {
        for (str1 = buffer; ; count++, str1 = NULL) {
            token = strtok_r(str1, delim, &saveptr1);
            if (token == NULL)
                break;
            printf("%d: %s\n", count, token);
        }
    }
    
    // Closing the file
    int close_status = fclose(file_pointer);

    if (close_status != 0) {
        printf("File could not be closed.");
        exit(EXIT_FAILURE);
    }
    
    exit(EXIT_SUCCESS);
}
