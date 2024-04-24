#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* argv[])
{
    char* argvCpy[10] = { NULL }; // Initialized all elements to NULL for safety

    // Adjusted the loop to correctly copy all arguments
    for(int i = 0; i < argc; i++)
    {
        // Added +1 for the null terminator in the malloc call
        argvCpy[i] = (char*) malloc(strlen(argv[i]) + 1);

        // Check if malloc returned NULL (Memory Allocation Failed)
        if (argvCpy[i] == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return 1; // Return with error code
        }
        
        // Using strcpy to automatically copy the null terminator
        strcpy(argvCpy[i], argv[i]);

        printf("\nCount: %d, string: %s", i, argvCpy[i]);
    }

    // Example cleanup code to avoid memory leaks
    for(int i = 0; i < argc; i++)
    {
        free(argvCpy[i]);
    }

    return 0;
}
