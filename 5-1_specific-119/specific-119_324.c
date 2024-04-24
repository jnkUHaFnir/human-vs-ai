#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int x = 5; // Number of strings
    char **array_of_strings = malloc(x * sizeof(char *)); // Step 1

    if (array_of_strings == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < x; i++) {
        array_of_strings[i] = malloc(51 * sizeof(char)); // Step 2

        if (array_of_strings[i] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        // Optionally, you can initialize the string to an empty string like this:
        // array_of_strings[i][0] = '\0';
    }

    // Now you have successfully allocated memory for the array of strings
    // You can use array_of_strings[i] to access each string within the array

    // Don't forget to free the memory when you are done
    for (int i = 0; i < x; i++) {
        free(array_of_strings[i]);
    }
    free(array_of_strings);

    return 0;
}
