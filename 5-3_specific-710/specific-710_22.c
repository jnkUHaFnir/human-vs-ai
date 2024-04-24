#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num_strings = 5; // Number of strings you want to store

    // Allocate memory for array of strings
    char** array_of_strings = (char**)malloc(num_strings * sizeof(char*));

    // Check if allocation was successful
    if (array_of_strings == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Allocate memory for each individual string
    for (int i = 0; i < num_strings; i++) {
        array_of_strings[i] = (char*)malloc(51 * sizeof(char)); // Allocating memory for 50 characters + 1 for null terminator
        if (array_of_strings[i] == NULL) {
            printf("Memory allocation failed for string %d. Exiting...\n", i);
            return 1;
        }
        strcpy(array_of_strings[i], "Hello"); // Example: initialize the string
    }

    // Usage example: print the strings
    for (int i = 0; i < num_strings; i++) {
        printf("String %d: %s\n", i, array_of_strings[i]);
    }

    // Free allocated memory
    for (int i = 0; i < num_strings; i++) {
        free(array_of_strings[i]);
    }
    free(array_of_strings);

    return 0;
}
