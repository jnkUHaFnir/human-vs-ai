#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

int main() {
    int x = 10; // Number of strings
    char** array_of_strings;

    // Allocate memory for array of strings
    array_of_strings = (char**)calloc(x, sizeof(char*));
    if (array_of_strings == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Allocate memory for each individual string
    for (int i = 0; i < x; i++) {
        array_of_strings[i] = (char*)calloc(MAX_LENGTH, sizeof(char));
        if (array_of_strings[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
    }

    // Use the array of strings...

    // Don't forget to free the memory when done
    for (int i = 0; i < x; i++) {
        free(array_of_strings[i]);
    }
    free(array_of_strings);

    return 0;
}
