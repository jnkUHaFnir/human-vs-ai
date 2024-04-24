#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char program_name[] = "/usr/local/bin/some_program";
    char argument_1[] = "foo";
    char argument_2[] = "foo2";
    char space[] = " ";
    
    // Calculate total length needed for the command string
    size_t total_length = strlen(program_name) + 2 * strlen(space) +
                          strlen(argument_1) + 2 * strlen(space) +
                          strlen(argument_2) + 1;

    char *runProgram = malloc(total_length);
    
    if (runProgram == NULL) {
        fprintf(stderr, "Memory allocation failed. Exiting...\n");
        return 1;
    }

    strcpy(runProgram, program_name);
    strcat(runProgram, space);
    strcat(runProgram, argument_1);
    strcat(runProgram, space);
    strcat(runProgram, argument_2);

    system(runProgram);
    
    free(runProgram);
    return 0;
}
