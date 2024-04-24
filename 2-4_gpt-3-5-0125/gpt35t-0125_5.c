// Allocate memory for a new 2-dimensional array
int **new_place_table = (int **)malloc((new_no_places+1)*sizeof(int *));
for(int i = 1; i <= new_no_places; i++) {
    new_place_table[i] = (int *)malloc((new_no_places+1)*sizeof(int));
}

// Copy elements from old array to new array
for(int i = 1; i <= (no_places < new_no_places ? no_places : new_no_places); i++) {
    for(int j = 1; j <= (no_places < new_no_places ? no_places : new_no_places); j++) {
        new_place_table[i][j] = place_table[i][j];
    }
}

// Free memory for old array
for(int i = 1; i <= no_places; i++) {
    free(place_table[i]);
}
free(place_table);

// Assign new array to the old array
place_table = new_place_table;
no_places = new_no_places;
