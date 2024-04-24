#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* argv[])
{
    int argcCpy = argc;
    char* argvCpy[10] = {};

    for (argcCpy = argc - 1; argcCpy >= 0; argcCpy--)
    {
        argvCpy[argcCpy] = (char *)malloc(strlen(argv[argcCpy]) + 1); // +1 for null terminator
        if (argvCpy[argcCpy] == NULL) {
            fprintf(stderr, "Memory allocation failed.");
            exit(1);
        }
        strcpy(argvCpy[argcCpy], argv[argcCpy]);
        printf("\nCount: %d, string: %s", argcCpy, argvCpy[argcCpy]);
    }

    // Free dynamically allocated memory
    for (argcCpy = argc - 1; argcCpy >= 0; argcCpy--) {
        free(argvCpy[argcCpy]);
    }

    return 0;
}
