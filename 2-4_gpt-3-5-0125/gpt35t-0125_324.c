#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 10; // Number of strings
    char** array = (char**)malloc(x * sizeof(char*));

    for (int i = 0; i < x; i++) {
        array[i] = (char*)malloc(51 * sizeof(char)); // Allocating memory for each string
    }

    // Use the array here

    // Free allocated memory
    for (int i = 0; i < x; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
