#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_strings = 5; // Number of strings
    int max_length = 50; // Maximum length of each string

    // Allocate memory for array of strings
    char** array_of_strings = (char**)malloc(num_strings * sizeof(char*));
    if (array_of_strings == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < num_strings; i++) {
        array_of_strings[i] = (char*)malloc((max_length + 1) * sizeof(char));
        if (array_of_strings[i] == NULL) {
            printf("Memory allocation failed for string %d.\n", i);
            return 1;
        }
    }

    // Use the array_of_strings here

    // Don't forget to free the allocated memory after you are done
    for (int i = 0; i < num_strings; i++) {
        free(array_of_strings[i]);
    }
    free(array_of_strings);

    return 0;
}
