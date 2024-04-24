// Initially allocate memory for place_table
int **place_table = (int **)malloc((no_places+1) * sizeof(int *));
for (i = 0; i <= no_places; i++) {
    place_table[i] = (int *)malloc((no_places+1) * sizeof(int));
}

// If the size needs to be changed to new_no_places
int new_no_places = 10; // For example

// Reallocate memory for place_table
place_table = (int **)realloc(place_table, (new_no_places+1) * sizeof(int *));
for (i = 0; i <= new_no_places; i++) {
    place_table[i] = (int *)realloc(place_table[i], (new_no_places+1) * sizeof(int));
}
