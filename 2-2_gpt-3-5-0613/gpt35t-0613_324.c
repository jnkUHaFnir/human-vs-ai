#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 10; // Number of strings

    // Allocate memory for array of x strings
    char** array = (char**)malloc(x * sizeof(char*));

    // Allocate memory for each individual string in the array
    for (int i = 0; i < x; i++) {
        array[i] = (char*)malloc(51 * sizeof(char));
    }

    // Use the array for your program

    // Free the memory when done
    for (int i = 0; i < x; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
