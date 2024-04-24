#include <stdio.h>
#include <stdlib.h>

int main() {
    int **place_table;
    int no_places = 5; // Initial number of places
    int new_no_places;
    int i;

    // Allocate initial 2D array
    place_table = (int **)malloc((no_places + 1) * sizeof(int *));
    for(i = 1; i <= no_places; i++) {
        place_table[i] = (int *)malloc((no_places + 1) * sizeof(int));
    }
    
    // Reallocating 2D array
    new_no_places = 10; // New number of places
    place_table = (int **)realloc(place_table, (new_no_places + 1) * sizeof(int *));
    
    // Check if the reallocation was successful before using place_table
    if (place_table != NULL) {
        // Allocate or Reallocate additional rows
        for(i = no_places + 1; i <= new_no_places; i++) {
            place_table[i] = (int *)malloc((new_no_places + 1) * sizeof(int));
        }

        // Reallocate each existing row if needed (change in the number of columns)
        for(i = 1; i <= no_places; i++) {
            place_table[i] = (int *)realloc(place_table[i], (new_no_places + 1) * sizeof(int));
            // You have to check here again that reallocation was successful
        }
    } else {
        // Handle reallocation failure (perhaps by printing an error message and exiting)
    }

    // Remember to free allocated memory when done
    for(i = 1; i <= new_no_places; i++) {
        free(place_table[i]);
    }
    free(place_table);

    return 0;
}
