#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char* argv[])
{   
    int argcCpy = argc;
    char* argvCpy[10] = {};

    for(argcCpy = argc-1; argcCpy >= 0; argcCpy--) // Start from argc-1
    {   
        argvCpy[argcCpy] = (char *) malloc(strlen(argv[argcCpy]) + 1); // Allocate one extra character for null-terminator
        memcpy(argvCpy[argcCpy], argv[argcCpy], strlen(argv[argcCpy]) + 1); // Copy the null-terminator as well
        printf("\nCount: %d, string: %s", argcCpy, argvCpy[argcCpy]);
    }
    return 0;
}
// After using the copied strings
for(int i = 0; i < argc; i++)
{
    free(argvCpy[i]);
}
