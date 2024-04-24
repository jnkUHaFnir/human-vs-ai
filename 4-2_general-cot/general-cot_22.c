#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int x = 5; // Number of strings
    int max_length = 50;

    // Allocate memory for an array of x pointers to strings
    char **array_of_strings = (char **)malloc(sizeof(char *) * x);

    if (array_of_strings == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    // Allocate memory for each string
    for (int i = 0; i < x; i++) {
        array_of_strings[i] = (char *)malloc(sizeof(char) * max_length);
        if (array_of_strings[i] == NULL) {
            printf("Memory allocation failed");
            return 1;
        }
        // Initialize the string, for example purposes
        snprintf(array_of_strings[i], max_length, "String %d", i+1);
    }

    // Access and print the strings
    for (int i = 0; i < x; i++) {
        printf("String %d: %s\n", i+1, array_of_strings[i]);
    }

    // Free memory
    for (int i = 0; i < x; i++) {
        free(array_of_strings[i]);
    }
    free(array_of_strings);

    return 0;
}
