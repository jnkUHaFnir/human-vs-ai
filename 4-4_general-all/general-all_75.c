#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* argv[])
{   
    int argcCpy = argc;
    char* argvCpy[10] = {};

    for(argcCpy = argc - 1; argcCpy >= 0; argcCpy--)
    {   
        argvCpy[argcCpy] = (char*)malloc(strlen(argv[argcCpy]) + 1);
        strcpy(argvCpy[argcCpy], argv[argcCpy]);
        printf("\nCount: %d, string: %s", argcCpy, argvCpy[argcCpy]);
    }

    // Free memory after usage
    for(int i = 0; i < argc; i++)
    {
        free(argvCpy[i]);
    }

    return 0;
}
