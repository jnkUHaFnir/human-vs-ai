#include <stdio.h>
#include <stdlib.h>

int main() {
    int **place_table;
    int no_places = 5; // Initial size
    int i;

    // Allocate initial 2D array
    place_table = (int **)malloc((no_places+1) * sizeof(int *));
    for (i = 1; i <= no_places; i++) {
        place_table[i] = (int *)malloc((no_places+1) * sizeof(int));
    }
    
    // Assuming you want to resize the 2D array
    int new_no_places = 10; // New size

    // Step 1: Reallocate memory for the array of pointers (1st dimension)
    place_table = (int **)realloc(place_table, (new_no_places+1) * sizeof(int *));
    if (place_table == NULL) {
        // Handle realloc failure
    }

    // Step 2: Reallocate memory for each row
    for (i = 1; i <= new_no_places; i++) {
        if (i <= no_places) {
            // For existing rows that continue to exist, optionally resize them
            place_table[i] = (int *)realloc(place_table[i], (new_no_places+1) * sizeof(int));
            if (place_table[i] == NULL) {
                // Handle realloc failure
            }
        } else {
            // For entirely new rows
            place_table[i] = (int *)malloc((new_no_places+1) * sizeof(int));
            if (place_table[i] == NULL) {
                // Handle malloc failure
            }
        }
    }

    // If shrinking the array, don't forget to free the removed rows
    if (new_no_places < no_places) {
        for (i = new_no_places + 1; i <= no_places; i++) {
            free(place_table[i]);
        }
    }

    // Use your updated 2D array...

    // Don't forget to free the memory when done
    for (i = 1; i <= new_no_places; i++) {
        free(place_table[i]);
    }
    free(place_table);

    return 0;
}
