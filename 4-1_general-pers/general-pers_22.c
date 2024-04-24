#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 50

int main() {
    int x = 10; // Number of strings

    // Allocate memory for an array of x strings
    char** array_of_strings = (char**)malloc(x * sizeof(char*));

    if (array_of_strings == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for each individual string
    for (int i = 0; i < x; i++) {
        array_of_strings[i] = (char*)malloc((MAX_LEN + 1) * sizeof(char)); // +1 for the null terminator
        if (array_of_strings[i] == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
    }

    // Use the array_of_strings as needed

    // Don't forget to free the allocated memory when done
    for (int i = 0; i < x; i++) {
        free(array_of_strings[i]);
    }

    free(array_of_strings);

    return 0;
}
