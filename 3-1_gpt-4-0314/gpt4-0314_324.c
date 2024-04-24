#include <stdio.h>
#include <stdlib.h>

int main() {
    int x; // number of strings
    scanf("%d", &x);

    char **array_of_strings = malloc(x * sizeof(char*)); // Allocate memory for 'x' string pointers

    for (int i = 0; i < x; i++) {
        array_of_strings[i] = malloc(50 * sizeof(char)); // Allocate memory for each individual string
    }

    // Now you can use the array_of_strings to store 'x' strings, each of maximum 50 characters

    // Don't forget to free the memory when you're done using the array
    for (int i = 0; i < x; i++) {
        free(array_of_strings[i]);
    }
    free(array_of_strings);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x; // number of strings
    scanf("%d", &x);

    char **array_of_strings = calloc(x, sizeof(char*)); // Allocate memory for 'x' string pointers

    for (int i = 0; i < x; i++) {
        array_of_strings[i] = calloc(50, sizeof(char)); // Allocate memory for each individual string
    }

    // Now you can use the array_of_strings to store 'x' strings, each of maximum 50 characters

    // Don't forget to free the memory when you're done using the array
    for (int i = 0; i < x; i++) {
        free(array_of_strings[i]);
    }
    free(array_of_strings);

    return 0;
}
