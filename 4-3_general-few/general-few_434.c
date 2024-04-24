// Reallocate memory for the 2D array
place_table = (int **)realloc(place_table, (no_places+1) * sizeof(int *));

for(i = 1; i <= no_places; i++) {
    place_table[i] = (int *)realloc(place_table[i], (no_places+1) * sizeof(int));
}
