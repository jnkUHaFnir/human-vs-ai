#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char program_name[] = "/usr/local/bin/some_program";
    char argument_1[] = "foo";
    char argument_2[] = "foo2";
    char space[] = " ";
    // Calculate the total size needed for the command
    size_t runProgramSize = strlen(program_name) + strlen(argument_1) +
                            strlen(argument_2) + strlen(space) * 2 + 1; // Space for two spaces and the null terminator

    // Allocate memory for the command
    char *runProgram = malloc(runProgramSize);
    if (!runProgram) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    // Build the command string
    strcpy(runProgram, program_name);
    strcat(runProgram, space);
    strcat(runProgram, argument_1);
    strcat(runProgram, space);
    strcat(runProgram, argument_2);

    // Execute the command
    int system_result = system(runProgram);
    if (system_result == -1) {
        perror("System call failed");
        free(runProgram);
        exit(EXIT_FAILURE);
    }

    // Free the allocated memory
    free(runProgram);
    return 0;
}
