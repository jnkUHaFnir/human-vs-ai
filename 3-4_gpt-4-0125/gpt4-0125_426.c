#include <stdio.h>

// Declare a global 2D array with 3 rows and 4 columns
int numbers[3][4];

int main() {
    // You can now use 'numbers' here
    numbers[0][0] = 1; // Just an example of setting a value
    printf("%d\n", numbers[0][0]); // And printing it

    return 0;
}
#include <stdio.h>

// Initialize a global 2D array. The size of the first dimension is inferred.
int numbers[][4] = {
    {1, 2, 3, 4}, // Row 0
    {5, 6, 7, 8}, // Row 1
    {9, 0, 1, 2}  // Row 2
}; // This array has 3 rows and 4 columns, derived from the initialization.

int main() {
    // You can access 'numbers' here
    for (int i = 0; i < 3; i++) { // Iterate through the rows
        for (int j = 0; j < 4; j++) { // Iterate through the columns
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int **dynamicNumbers; // Pointer to pointer (to rows of int pointers)

int main() {
    int rows = 3;
    int cols = 4;

    // Allocate an array of int pointers (rows)
    dynamicNumbers = malloc(rows * sizeof(int*));

    // For each row, allocate columns
    for (int i = 0; i < rows; i++) {
        dynamicNumbers[i] = malloc(cols * sizeof(int));
        // Optionally Initialize elements, for example to 0
        for (int j = 0; j < cols; j++) {
            dynamicNumbers[i][j] = 0; // Set to 0 or any initial value
        }
    }

    // Use 'dynamicNumbers' similar to the static array
    // Just remember to free the allocated memory when done
    // Starting from freeing each row
    for (int i = 0; i < rows; i++) {
        free(dynamicNumbers[i]); 
    }
    // And then the array of pointers itself
    free(dynamicNumbers);

    return 0;
}
