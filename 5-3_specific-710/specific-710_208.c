#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char program_name[] = "/usr/local/bin/some_program";
    char argument_1[] = "foo";
    char argument_2[] = "foo2";
    char space[] = " ";
    
    size_t program_len = strlen(program_name);
    size_t argument_1_len = strlen(argument_1);
    size_t argument_2_len = strlen(argument_2);
    size_t space_len = strlen(space);

    // Calculate the total length needed and allocate memory
    char *runProgram = malloc(program_len + argument_1_len + argument_2_len + 2 * space_len + 1);

    // Copy the program name and arguments to runProgram
    strcpy(runProgram, program_name);
    strcat(runProgram, space);
    strcat(runProgram, argument_1);
    strcat(runProgram, space);
    strcat(runProgram, argument_2);

    system(runProgram);
    free(runProgram);
    return 0;
}
