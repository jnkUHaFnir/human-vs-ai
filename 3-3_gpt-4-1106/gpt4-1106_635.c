#include <stdio.h>
#include <stdlib.h> // Include for malloc() and free()

void createArr(int*** arrPtr, int x, int y);

int main() {
    int x, y;       // Dimensions
    int i, j;       // Loop indexes
    int** arr;      // 2D array pointer
    x = 3;
    y = 4;

    createArr(&arr, x, y);

    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (i = 0; i < x; ++i) {
        free(arr[i]);
    }
    free(arr);

    getch(); // Note: _getch() might be specific to certain compilers/platforms.
    return 0;   
}

void createArr(int*** arrPtr, int x, int y) {
    int i, j;       // Loop indexes

    // Allocate the outer array of pointers
    *arrPtr = malloc(x * sizeof(int*));
    if (*arrPtr == NULL) {
        // Handle allocation failure
        perror("Allocation failed");
        exit(EXIT_FAILURE);
    }
    
    // Allocate the inner arrays
    for (i = 0; i < x; ++i) {
        (*arrPtr)[i] = malloc(y * sizeof(int));
        if ((*arrPtr)[i] == NULL) {
            // Handle allocation failure
            perror("Allocation failed");
            exit(EXIT_FAILURE);
        }
    }

    // Initialize the array with some values
    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            (*arrPtr)[i][j] = i + j;
        }
    }  
}
