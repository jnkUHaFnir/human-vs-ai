#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char program_name[] = "/usr/local/bin/some_program";
    char argument_1[] = "foo";
    char argument_2[] = "foo2";
    char space[] = " ";
    
    // Calculate total size needed for the runProgram
    size_t total_size = strlen(program_name) + strlen(argument_1) +
                        strlen(argument_2) + 2 * strlen(space) + 1; // +1 for null terminator

    // Allocate memory and check for allocation success
    char *runProgram = malloc(total_size);
    if (runProgram == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Construct the runProgram string
    strcpy(runProgram, program_name);
    strcat(runProgram, space);
    strcat(runProgram, argument_1);
    strcat(runProgram, space);
    strcat(runProgram, argument_2);

    // Execute the command
    system(runProgram);

    // Free allocated memory
    free(runProgram);

    return 0;
}
