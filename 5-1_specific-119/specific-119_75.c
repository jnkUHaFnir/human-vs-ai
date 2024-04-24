#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* argv[])
{   
    int argcCpy;
    char* argvCpy[10] = {};

    for(argcCpy = argc-1; argcCpy>=0; argcCpy--)
    {   
        argvCpy[argcCpy] = (char *) malloc(strlen(argv[argcCpy]) + 1); // Add 1 for null terminator
        strncpy(argvCpy[argcCpy], argv[argcCpy], strlen(argv[argcCpy]) + 1); // Copy including null terminator
        argvCpy[argcCpy][strlen(argv[argcCpy])] = '\0'; // Null terminate manually if destination buffer is not erased by the function
        
        printf("\nCount: %d, string: %s", argcCpy, argvCpy[argcCpy]);
    }

    // Don't forget to free the memory
    for(argcCpy = argc-1; argcCpy>=0; argcCpy--)
    {
        free(argvCpy[argcCpy]);
    }

    return 0;
}
