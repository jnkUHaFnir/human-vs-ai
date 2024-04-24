#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // Determine the length of the resulting string
    size_t length = 0;
    for (int i = 1; i < argc; ++i) {
        length += strlen(argv[i]) + 1; // +1 for space or null terminator
    }

    // Allocate memory for the resulting string
    char* str = malloc(length);
    if (str == NULL) {
        perror("malloc");
        return 1;
    }

    // Concatenate arguments into the string
    str[0] = '\0'; // Initialize the string as empty
    for (int i = 1; i < argc; ++i) {
        strcat(str, argv[i]);
        if (i < argc - 1) {
            strcat(str, " "); // Add a space between arguments
        }
    }

    // Now `str` contains all the arguments in a single string
    printf("The whole command line was: %s\n", str);

    // Don't forget to free the memory
    free(str);

    return 0;
}
