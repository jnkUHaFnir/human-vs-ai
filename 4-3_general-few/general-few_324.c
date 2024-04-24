#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 10; // Number of strings
    char **array; // Array of strings

    // Allocate memory for the array
    array = (char **)malloc(x * sizeof(char *));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < x; i++) {
        // Allocate memory for each string
        array[i] = (char *)malloc(50 * sizeof(char));
        if (array[i] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        // You can now use array[i] to store your strings
    }

    // Don't forget to free the memory when you are done
    for (int i = 0; i < x; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
