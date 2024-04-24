#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* argv[])
{   
    int argcCpy;
    char* argvCpy[10] = {};

    for(argcCpy = argc - 1; argcCpy >= 0; argcCpy--)
    {   
        argvCpy[argcCpy] = (char *) malloc(strlen(argv[argcCpy]) + 1);
        if (argvCpy[argcCpy] == NULL) {
            fprintf(stderr, "Memory allocation failed");
            exit(1);
        }

        memcpy(argvCpy[argcCpy], argv[argcCpy], strlen(argv[argcCpy));
        argvCpy[argcCpy][strlen(argv[argcCpy])] = '\0'; // Add null terminator
        printf("\nCount: %d, string: %s", argcCpy, argvCpy[argcCpy]);
    }

    // Free allocated memory
    for(argcCpy = argc - 1; argcCpy >= 0; argcCpy--) {
        free(argvCpy[argcCpy]);
    }

    return 0;
}
