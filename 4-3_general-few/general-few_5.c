// Allocate memory for the initial 2D array
place_table = (int **)malloc((no_places+1)*sizeof(int *));
for(i = 1; i <= no_places; i++)
    place_table[i] = (int *)malloc((no_places+1)*sizeof(int));

// If the size needs to be changed, reallocate memory
int new_no_places = 10; // New size for no_places
place_table = (int **)realloc(place_table, (new_no_places+1)*sizeof(int *));
for(i = 1; i <= new_no_places; i++) {
    if (i > no_places) {
        place_table[i] = (int *)malloc((no_places+1)*sizeof(int));
    } else {
        place_table[i] = (int *)realloc(place_table[i], (no_places+1)*sizeof(int));
    }
}

// Update the no_places variable
no_places = new_no_places;
