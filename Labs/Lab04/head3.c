/* Kartikeya Sharma
 * February 5, 2019 @ 1 PM
 * lab 04 - head3.c
 * compile with: make head3
 * notes: This program acts similarly 
 *        to the head command, except
 *        data is read in lines rather
 *        than bytes.
 */

#include "fileio.h"

/*
 * Coordinates reading a particular number of lines
 * of data (default: 10) from a file; exits with an
 * error if unsuccessful
 *
 * argc: number of command line arguments inputted
 * argv: array of command line arguments inputted
 * Return value: 0 if the program runs successfully (without error)
 */
int main(int argc, char* argv[])
{
    int read_num_lines = 10;              // default to 10 lines of data
    char buffer[MAXLINES][MAXBYTES+1];    // buffer to hold file data

    if (argc < 2){
        // missing required argument
        printf("Usage %s <filename> [<num_lines>]\n", 
                argv[0]);
        exit(-1);
    }
    if (argc > 2){
        // process optional lines argument
        read_num_lines = atoi(argv[2]);
        if (read_num_lines > MAXLINES){            
            printf("number of lines is too large,\
                    max supported value is %d!\n",\
                    MAXLINES);
            exit(-2);
        }
    }
    
    // Opening the file
    int file_descriptor = open(argv[1], O_RDONLY);
    if (file_descriptor == -1) {
        printf("Error occured while trying to open the file.\
                Please check the inputted file path.");
        exit(-3);
    }

    // Reading the file
    int read_status = read_file_lines(argv[1], buffer); 
    if (read_status >= 0) {
        int num_line;
        for (num_line = 0; num_line < MAXLINES; num_line++) {
            printf("%s", buffer[num_line]);
        }
    } else if (read_status == -1) {
        printf("Error: could not close file %s\n", argv[1]);
        exit(-4);
    } else {
        printf("Error: could not read file!\n");
        exit(-5);
    }

    return 0;
}
