#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 50

int main() {
    int num_strings = 10; // Number of strings to allocate
    char **array_of_strings = (char **)malloc(num_strings * sizeof(char *));

    if (array_of_strings == NULL) {
        // Handle allocation failure
        return 1;
    }

    for (int i = 0; i < num_strings; i++) {
        array_of_strings[i] = (char *)malloc((MAX_STRING_LENGTH + 1) * sizeof(char)); // +1 for null terminator
        if (array_of_strings[i] == NULL) {
            // Handle allocation failure
            return 1;
        }
    }

    // Now you have allocated memory for an array of x strings, each of length MAX_STRING_LENGTH

    // Don't forget to free the memory when you are done using it
    for (int i = 0; i < num_strings; i++) {
        free(array_of_strings[i]);
    }
    free(array_of_strings);

    return 0;
}
