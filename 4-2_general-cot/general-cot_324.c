#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int x = 10; // Number of strings
    int string_length = 50; // Maximum length of each string

    // Calculate total size needed for x strings of 50 characters
    int total_size = (string_length + 1) * x * sizeof(char);

    // Allocate memory for the array of strings
    char** array_of_strings = (char**)malloc(x * sizeof(char*));

    if (array_of_strings == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Allocate memory for each string
    for (int i = 0; i < x; i++) {
        array_of_strings[i] = (char*)malloc((string_length + 1) * sizeof(char));
        if (array_of_strings[i] == NULL) {
            printf("Memory allocation failed. Exiting...\n");
            return 1;
        }
        // Initialize the string to empty
        array_of_strings[i][0] = '\0';
    }

    // Usage example: strcpy to copy a string into the array
    strcpy(array_of_strings[0], "Hello");

    // Use the array_of_strings here

    // Don't forget to free the memory
    for (int i = 0; i < x; i++) {
        free(array_of_strings[i]);
    }
    free(array_of_strings);

    return 0;
}
