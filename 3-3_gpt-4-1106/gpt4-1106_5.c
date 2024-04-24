#include <stdio.h>
#include <stdlib.h>

int **realloc2DArray(int **array, int old_rows, int new_rows, int new_cols) {
    if (new_rows < old_rows) {
        // Free the rows that are no longer needed
        for (int i = new_rows; i < old_rows; i++) {
            free(array[i]);
        }
    }

    // Reallocate the array of row pointers
    array = (int **)realloc(array, new_rows * sizeof(int *));
    if (!array) {
        perror("Failed to reallocate row pointers");
        return NULL;
    }

    // Allocate the new rows
    for (int i = 0; i < new_rows; i++) {
        // Reallocate existing rows or allocate new ones if necessary
        if (i < old_rows) {
            array[i] = (int *)realloc(array[i], new_cols * sizeof(int));
            if (!array[i]) {
                perror("Failed to reallocate row");
                // Handle the error: free already allocated rows and return NULL
            }
        } else {
            array[i] = (int *)malloc(new_cols * sizeof(int));
            if (!array[i]) {
                perror("Failed to allocate new row");
                // Handle the error: free already allocated rows and return NULL
            }
        }
    }
    
    // Return the reallocated array
    return array;
}

int main() {
    int **place_table;
    int no_places = 5; // Initial size

    // Allocate the initial 2D array
    place_table = (int **)malloc(no_places * sizeof(int *));
    for (int i = 0; i < no_places; i++) {
        place_table[i] = (int *)malloc(no_places * sizeof(int));
    }

    // Now you want to change the size
    int new_no_places = 7; // New size, for example

    // Reallocate with the new size
    place_table = realloc2DArray(place_table, no_places, new_no_places, new_no_places);

    // After usage, free the memory
    for (int i = 0; i < new_no_places; i++) {
        free(place_table[i]);
    }
    free(place_table);

    return 0;
}
