#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* argv[])
{   
    int argcCpy = argc;
    char* argvCpy[10] = {};

    for(argcCpy = argc - 1; argcCpy > 0; argcCpy--)
    {   
        argvCpy[argcCpy] = (char *) malloc(strlen(argv[argcCpy]) + 1);
        if (argvCpy[argcCpy] == NULL) {
            printf("Memory allocation failed");
            return 1;
        }
        strcpy(argvCpy[argcCpy], argv[argcCpy]);
        printf("\nCount: %d, string: %s", argcCpy, argvCpy[argcCpy]);
    }

    // Remember to free the allocated memory
    for(argcCpy = argc - 1; argcCpy > 0; argcCpy--)
    {
        free(argvCpy[argcCpy]);
    }
    return 0;
}
