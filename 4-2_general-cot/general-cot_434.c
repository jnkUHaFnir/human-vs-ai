#include <stdio.h>
#include <stdlib.h>

int main() {
    int **place_table = NULL;
    int no_places = 3; // Initial size
    int new_no_places = 5; // New size
    int i, j;

    // Allocate memory for the 2D array
    place_table = (int **)malloc((no_places + 1) * sizeof(int *));
    for (i = 1; i <= no_places; i++) {
        place_table[i] = (int *)malloc((no_places + 1) * sizeof(int));
    }

    // Example: Copy existing values

    // Reallocate memory for the 2D array with new size
    int **temp_table = (int **)malloc((new_no_places + 1) * sizeof(int *));
    for (i = 1; i <= new_no_places; i++) {
        temp_table[i] = (int *)malloc((new_no_places + 1) * sizeof(int));
    }

    // Copy existing values to the new array
    for (i = 1; i <= no_places; i++) {
        for (j = 1; j <= no_places; j++) {
            temp_table[i][j] = place_table[i][j];
        }
        free(place_table[i]); // Free the old memory
    }
    
    free(place_table);
    place_table = temp_table;

    // Now place_table holds the updated 2D array with new size

    // Don't forget to free the memory when you no longer need it
    for (i = 1; i <= new_no_places; i++) {
        free(place_table[i]);
    }
    free(place_table);

    return 0;
}
