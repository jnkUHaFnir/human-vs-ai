#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    // Calculate the total size needed to store all arguments
    size_t total_size = 0;
    for (int i = 0; i < argc; i++) {
        total_size += strlen(argv[i]) + 1; // Add 1 for space/terminating null character
    }

    // Allocate memory for the concatenated string
    char *cmd_line = (char *)malloc(total_size);
    if (cmd_line == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Concatenate all arguments into a single string
    cmd_line[0] = '\0'; // Ensure an empty string at the beginning
    for (int i = 0; i < argc; i++) {
        strcat(cmd_line, argv[i]);
        strcat(cmd_line, " "); // Add space between arguments
    }

    // Print the whole command line
    printf("Whole command line: %s\n", cmd_line);

    // Free the dynamically allocated memory
    free(cmd_line);

    return 0;
}
