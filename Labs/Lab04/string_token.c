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
        printf("./string_token <file name>\n");
        exit(EXIT_FAILURE);
    }

    // Opening the file
    FILE *file_pointer = fopen(argv[1], "r");

    if (file_pointer == NULL) {
        printf("File could not be opened.\
 Please check the inputted\
 filepath.\n");
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
