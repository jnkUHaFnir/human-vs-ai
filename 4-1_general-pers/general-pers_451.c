#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *global = NULL;

int main() {
    printf("Please Enter Text: \n");

    // Allocate memory for global and extra space for the null terminator
    global = (char*)malloc(100 * sizeof(char)); // Allocate initial memory for 100 characters
    if (global == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read a line of text including spaces using fgets
    if (fgets(global, 100, stdin) == NULL) {
        printf("Error reading input.\n");
        free(global); // Free memory before exiting
        return 1;
    }

    // Remove the newline character at the end if present
    size_t len = strlen(global);
    if (len > 0 && global[len - 1] == '\n') {
        global[len - 1] = '\0';
    }

    // Print the entered text
    printf("%s\n", global);

    // Free allocated memory
    free(global);

    return 0;
}
