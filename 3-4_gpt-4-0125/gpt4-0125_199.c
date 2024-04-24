#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // Calculate the total length required for the command line string.
    // Allocate space for spaces between arguments and a null terminator.
    size_t totalLen = 0;
    for(int i = 0; i < argc; i++) {
        totalLen += strlen(argv[i]) + 1; // +1 for space or null terminator
    }

    // Dynamically allocate memory for the command line string.
    char *cmdLine = malloc(totalLen);
    if (cmdLine == NULL) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    // Copy and concatenate the arguments into cmdLine.
    cmdLine[0] = '\0'; // Initialize the string to be empty
    for(int i = 0; i < argc; i++) {
        strcat(cmdLine, argv[i]);
        if (i < argc - 1) {
            strcat(cmdLine, " "); // Add a space between arguments (but not after the last one)
        }
    }

    // Print the whole command line.
    printf("The whole command line is: %s\n", cmdLine);

    // Don't forget to free the dynamically allocated memory!
    free(cmdLine);

    return EXIT_SUCCESS;
}
