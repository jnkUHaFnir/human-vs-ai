#include <stdio.h>
#include <stdlib.h>

int main() {
    int no_places = 5; // Example value, this can vary based on your requirements
    int **place_table = (int **)malloc((no_places+1) * sizeof(int *));
    if (place_table == NULL) {
        // Handle memory allocation failure
        return 1;
    }

    for (int i = 1; i <= no_places; i++) {
        place_table[i] = (int *)malloc((no_places+1) * sizeof(int));
        if (place_table[i] == NULL) {
            // Handle memory allocation failure
            return 1;
        }
    }

    // Your code here

    // If no_places needs to be increased:
    int new_no_places = 10; // Example new value, this can vary based on your requirements
    int **new_place_table = (int **)realloc(place_table, (new_no_places+1) * sizeof(int *));
    if (new_place_table == NULL) {
        // Handle memory reallocation failure by freeing the original memory
        for (int i = 1; i <= no_places; i++) {
            free(place_table[i]);
        }
        free(place_table);
        return 1;
    }

    for (int i = no_places+1; i <= new_no_places; i++) {
        new_place_table[i] = (int *)malloc((new_no_places+1) * sizeof(int));
        if (new_place_table[i] == NULL) {
            // Handle memory allocation failure
            return 1;
        }
    }

    // Update no_places to new_no_places now
    no_places = new_no_places;
    place_table = new_place_table;

    // Use the updated place_table with the new dimensions

    // Don't forget to free the memory when done
    for (int i = 1; i <= no_places; i++) {
        free(place_table[i]);
    }
    free(place_table);

    return 0;
}
