#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char program_name[] = "/usr/local/bin/some_program";
    char argument_1[] = "foo";
    char argument_2[] = "foo2";
    const char *space = " ";
    
    // Calculate the total length needed including spaces and null terminator
    size_t total_length = strlen(program_name) + strlen(argument_1) +
                          strlen(argument_2) + 2 * strlen(space) + 1;
    char *runProgram = malloc(total_length);

    if (runProgram == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    snprintf(runProgram, total_length, "%s%s%s%s%s", program_name, space, argument_1, space, argument_2);

    system(runProgram);

    free(runProgram);
    exit(0);
}
