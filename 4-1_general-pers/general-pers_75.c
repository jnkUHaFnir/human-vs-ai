#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char* argv[])
{
    int argcCpy = argc;
    char* argvCpy[10] = {};

    for(argcCpy = argc - 1; argcCpy > 0; argcCpy--)
    {
        argvCpy[argcCpy - 1] = (char *) malloc(strlen(argv[argcCpy]) + 1); // +1 for null terminator
        if (argvCpy[argcCpy - 1] == NULL) {
            // Handle malloc failure
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        memcpy(argvCpy[argcCpy - 1], argv[argcCpy], strlen(argv[argcCpy) + 1); // +1 to include null terminator
        argvCpy[argcCpy - 1][strlen(argv[argcCpy])] = '\0'; // Ensure the string is null-terminated
        printf("\nCount: %d, string: %s", argcCpy, argvCpy[argcCpy - 1]);
    }

    // Free allocated memory
    for (int i = 0; i < argc - 1; i++) {
        free(argvCpy[i]);
    }

    return 0;
}
