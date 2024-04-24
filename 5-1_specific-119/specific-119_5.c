#include <stdio.h>
#include <stdlib.h>

int main() {
    int no_places = 3; // Initial size of the 2D array
    int i;

    // Create a 2D array dynamically
    int **place_table = (int **)malloc((no_places + 1) * sizeof(int *));
    
    for (i = 1; i <= no_places; i++) {
        place_table[i] = (int *)malloc((no_places + 1) * sizeof(int));
    }

    // Now, let's say we want to resize the 2D array to a new size (new_no_places)
    int new_no_places = 5;
    int **temp = (int **)realloc(place_table, (new_no_places + 1) * sizeof(int *));
    
    if (temp != NULL) {
        place_table = temp;
        
        // Resize each row
        for (i = 1; i <= new_no_places; i++) {
            place_table[i] = (int *)realloc(place_table[i], (new_no_places + 1) * sizeof(int));
        }

        printf("Memory reallocated successfully!\n");

        // Don't forget to free the memory when you're done using the array
        for (i = 1; i <= new_no_places; i++) {
            free(place_table[i]);
        }
        free(place_table);
    } else {
        printf("Memory reallocation failed!\n");
        // Handle the failure appropriately
    }

    return 0;
}
