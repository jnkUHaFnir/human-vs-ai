#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 50

int main() {
    int num_strings = 10; // Example number of strings

    // Allocate memory for an array of pointers to char
    char **array_of_strings = (char **)malloc(num_strings * sizeof(char *));

    if (array_of_strings == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Allocate memory for each individual string
    for (int i = 0; i < num_strings; i++) {
        array_of_strings[i] = (char *)malloc((MAX_STRING_LENGTH + 1) * sizeof(char));

        if (array_of_strings[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");

            // Free memory of previously allocated strings
            for (int j = 0; j < i; j++) {
                free(array_of_strings[j]);
            }
            free(array_of_strings);
            return 1;
        }
    }

    // Use the array_of_strings for your program

    // Don't forget to free the memory when you're done
    for (int i = 0; i < num_strings; i++) {
        free(array_of_strings[i]);
    }
    free(array_of_strings);

    return 0;
}
