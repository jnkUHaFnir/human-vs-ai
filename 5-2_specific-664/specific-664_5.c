#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a 2D array
int **allocate_2D_array(int rows, int cols) {
    int **array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
    }
    return array;
}

// Function to reallocate memory for a 2D array
int **reallocate_2D_array(int **array, int old_rows, int new_rows, int cols) {
    int **new_array = (int **)malloc(new_rows * sizeof(int *));
    
    for (int i = 0; i < new_rows; i++) {
        new_array[i] = (int *)malloc(cols * sizeof(int));
    }

    // Copy elements from the old array to the new array
    for (int i = 0; i < old_rows; i++) {
        for (int j = 0; j < cols; j++) {
            new_array[i][j] = array[i][j];
        }
    }

    // Free memory allocated for the old array
    for (int i = 0; i < old_rows; i++) {
        free(array[i]);
    }
    free(array);

    return new_array;
}

int main() {
    int **place_table;
    int no_places = 3;
    int new_no_places = 5;
    int i, j;

    // Allocate memory for a 2D array
    place_table = allocate_2D_array(no_places, no_places);

    // Use the 2D array and then decide to reallocate memory
    // For demonstration, let's just print some initial values
    for (i = 0; i < no_places; i++) {
        for (j = 0; j < no_places; j++) {
            place_table[i][j] = i + j;
            printf("%d ", place_table[i][j]);
        }
        printf("\n");
    }

    // Reallocate memory for the 2D array with a new size
    place_table = reallocate_2D_array(place_table, no_places, new_no_places, new_no_places);

    // For demonstration, let's print some new values after reallocation
    for (i = 0; i < new_no_places; i++) {
        for (j = 0; j < new_no_places; j++) {
            printf("%d ", place_table[i][j]);
        }
        printf("\n");
    }

    // Free memory allocated for the final 2D array
    for (i = 0; i < new_no_places; i++) {
        free(place_table[i]);
    }
    free(place_table);

    return 0;
}
