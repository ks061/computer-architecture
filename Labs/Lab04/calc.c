#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OP_INDEX 1
#define ARGS_START_INDEX 2
#define MIN_CMD_LINE_ARGS 3

void len_calc(int argc, char* argv[])
{
    int length = 0;
    int i;
    for (i = ARGS_START_INDEX; i < argc; i++) {
        length += strlen(argv[i]);
    }
    printf("%d\n", length);
}

void add_calc(int argc, char* argv[])
{
    float sum = 0.0;
    int i;
    for (i = ARGS_START_INDEX; i < argc; i++) {
        sum += atof(argv[i]);
    }
    printf("%.6f\n", sum);
}

void mult_calc(int argc, char* argv[])
{
    float product = 1;
    int i;
    for (i = ARGS_START_INDEX; i < argc; i++) {
        product *= atof(argv[i]);
    }
    printf("%.6f\n", product);
}

void div_calc(int argc, char* argv[])
{
    float quotient = atof(argv[ARGS_START_INDEX]);
    int i;
    for (i = ARGS_START_INDEX + 1; i < argc; i++) {
        quotient /= atof(argv[i]);
    }
    printf("%.6f\n", quotient);
}

void insuff_num_operands(int argc, char* argv[]) {
    printf("Unsupported arguments for the %s function.\
                     %d were needed, yet %d were provided.",\
                     argv[OP_INDEX], MIN_CMD_LINE_ARGS + 1,\
                     argc);
}

int main(int argc, char* argv[]) 
{
    if (argc < MIN_CMD_LINE_ARGS) { 
        printf("Usage: ./calc <operation> <arguments...>\n");
    }
    else if (strcmp(argv[OP_INDEX], "len") == 0) {
        len_calc(argc, argv);
    }
    else if (strcmp(argv[OP_INDEX], "add") == 0) {
        if (argc > MIN_CMD_LINE_ARGS) add_calc(argc, argv);
        else insuff_num_operands(argc, argv);
    }
    else if (strcmp(argv[OP_INDEX], "mult") == 0) {
        if (argc > MIN_CMD_LINE_ARGS) mult_calc(argc, argv);
        else insuff_num_operands(argc, argv);
    }
    else if (strcmp(argv[OP_INDEX], "div") == 0) {
        if (argc > MIN_CMD_LINE_ARGS) div_calc(argc, argv);
        else insuff_num_operands(argc, argv);
    }
    else {
        printf("Unsupported function, try: add, mult, div, or len\n");
    }

    return 0;
}
