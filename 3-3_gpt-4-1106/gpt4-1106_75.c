#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int argcCpy = argc;
    char* argvCpy[10] = {};

    // Start the loop from argc - 1 instead of argc to avoid accessing argv out of bounds
    for(argcCpy = argc - 1; argcCpy >= 0; argcCpy--)
    {
        // Need to allocate space for the null-terminating character as well by adding 1 to the length
        argvCpy[argcCpy] = (char *) malloc(strlen(argv[argcCpy]) + 1);

        // Make sure the malloc didn't fail
        if (argvCpy[argcCpy] == NULL) {
            fprintf(stderr, "\nFailed to allocate memory for argvCpy[%d]\n", argcCpy);
            return 1;
        }

        memcpy(argvCpy[argcCpy], argv[argcCpy], strlen(argv[argcCpy]) + 1); // +1 to copy the null terminator
        printf("\nCount: %d, string: %s", argcCpy, argvCpy[argcCpy]);
    }

    // It's good practice to free the allocated memory when done
    for (int i = 0; i < argc; i++) {
        free(argvCpy[i]);
    }

    return 0;
}
