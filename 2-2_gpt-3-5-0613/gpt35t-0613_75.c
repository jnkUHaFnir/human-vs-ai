#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* argv[])
{
    int argcCpy = argc;
    char* argvCpy[10] = {}; // You can adjust the size of the array according to your requirements

    for(argcCpy = argc - 1; argcCpy >= 0; argcCpy--)
    {
        argvCpy[argcCpy] = (char *) malloc(strlen(argv[argcCpy]) + 1); // +1 for null terminator
        memcpy(argvCpy[argcCpy], argv[argcCpy], strlen(argv[argcCpy]) + 1); // +1 for null terminator
        printf("\nCount: %d, string: %s", argcCpy, argvCpy[argcCpy]);
    }

    // Free the allocated memory
    for(argcCpy = argc - 1; argcCpy >= 0; argcCpy--)
    {
        free(argvCpy[argcCpy]);
    }

    return 0;
}
