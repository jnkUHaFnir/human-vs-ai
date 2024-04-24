// Free the existing memory for the 2D array
for (i = 1; i <= no_places; i++) {
    free(place_table[i]);
}
free(place_table);

// Reallocate memory for the 2D array with the new size
place_table = (int **)malloc((new_no_places+1) * sizeof(int *));
for (i = 1; i <= new_no_places; i++) {
    place_table[i] = (int *)malloc((new_no_places+1) * sizeof(int));
}
