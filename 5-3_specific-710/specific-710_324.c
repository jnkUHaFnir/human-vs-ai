#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int x = 5; // Number of strings
    int max_length = 50; // Maximum length of each string

    // Allocate memory for the array of strings
    char **array_of_strings = (char **)malloc(x * sizeof(char *));
    if (array_of_strings == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Allocate memory for each individual string
    for (int i = 0; i < x; i++) {
        array_of_strings[i] = (char *)malloc((max_length + 1) * sizeof(char)); // +1 for the null character
        if (array_of_strings[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
    }

    // You can now use array_of_strings as an array of x strings, each with max_length characters

    // Don't forget to free the memory when you're done with it
    for (int i = 0; i < x; i++) {
        free(array_of_strings[i]);
    }
    free(array_of_strings);

    return 0;
}
