int numbers[5][10];
int numbers[][10];
// Define a global 2D array with 5 rows and 10 columns
int numbers[5][10];
int numbers[5][10] = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},  // Row 0
    {10, 11, 12, 13, 14, 15, 16, 17, 18, 19},  // Row 1
    {20, 21, 22, 23, 24, 25, 26, 27, 28, 29},  // Row 2
    {30, 31, 32, 33, 34, 35, 36, 37, 38, 39},  // Row 3
    {40, 41, 42, 43, 44, 45, 46, 47, 48, 49}   // Row 4
};
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 5;
    int columns = 10;

    // Allocate memory for the 2D array
    int **numbers = malloc(rows * sizeof(int *));
    if(numbers == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < rows; i++) {
        numbers[i] = malloc(columns * sizeof(int));
        if(numbers[i] == NULL) {
            perror("Memory allocation failed");
            // Cleanup previously allocated rows before exiting
            for(int j = 0; j < i; j++) {
                free(numbers[j]);
            }
            free(numbers);
            exit(EXIT_FAILURE);
        }
    }

    // Use the array
    numbers[0][0] = 1; // Example assignment

    // Free the memory
    for(int i = 0; i < rows; i++) {
        free(numbers[i]);
    }
    free(numbers);

    return 0;
}
