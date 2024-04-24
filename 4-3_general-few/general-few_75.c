#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* argv[]) {   
    int argcCpy = argc;
    char* argvCpy[10] = {};

    for(argcCpy = argc - 1; argcCpy >= 0; argcCpy--) {   
        argvCpy[argcCpy] = (char *) malloc(strlen(argv[argcCpy]) + 1); // Allocate memory for string and null terminator
        memcpy(argvCpy[argcCpy], argv[argcCpy], strlen(argv[argcCpy)); // Copy the string
        argvCpy[argcCpy][strlen(argv[argcCpy])] = '\0'; // Add null terminator
        printf("\nCount: %d, string: %s", argcCpy, argvCpy[argcCpy]);
    }

    // Free allocated memory
    for(int i = 0; i < argc; i++) {
        free(argvCpy[i]);
    }

    return 0;
}
