#include <stdio.h>
#include <stdlib.h>

// Function to reallocate the 2D array
void reallocate2DArray(int ***array, int oldSize, int newSize) {
    int i;

    // Resize the array of pointers
    *array = (int **)realloc(*array, (newSize + 1) * sizeof(int *));

    if (newSize > oldSize) {
        // Initialize new rows
        for (i = oldSize + 1; i <= newSize; i++) {
            (*array)[i] = (int *)malloc((newSize + 1) * sizeof(int));
        }
    } else {
        // Free the surplus rows when newSize < oldSize
        for (i = newSize + 1; i <= oldSize; i++) {
            free((*array)[i]);
        }
        // Resize the remaining row arrays if the newSize is smaller
        for (i = 1; i <= newSize; i++) {
            (*array)[i] = (int *)realloc((*array)[i], (newSize + 1) * sizeof(int));
        }
    }
}

int main() {
    int **place_table;
    int i, no_places = 5;
    // Initial allocation
    place_table = (int **)malloc((no_places + 1) * sizeof(int *));
    for (i = 1; i <= no_places; i++) {
        place_table[i] = (int *)malloc((no_places + 1) * sizeof(int));
    }

    // Assuming at some point we need to resize
    int new_no_places = 8; // new size
    reallocate2DArray(&place_table, no_places, new_no_places);

    // Do something with place_table...

    // Free memory before exit
    for (i = 1; i <= new_no_places; i++) {
        free(place_table[i]);
    }
    free(place_table);

    return 0;
}
