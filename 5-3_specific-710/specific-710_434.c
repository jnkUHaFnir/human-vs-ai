// Free the memory allocated for the existing 2D array
for(i = 1; i <= no_places; i++) {
    free(place_table[i]);
}
free(place_table);

// Allocate memory for the new size of the array
place_table = (int **)malloc((new_no_places+1)*sizeof(int *));
for(i = 1; i <= new_no_places; i++) {
    place_table[i] = (int *)malloc((new_no_places+1)*sizeof(int));
}

// Copy contents of the old array to the new array (if needed)

// Free the memory of the old array (if needed)
for(i = 1; i <= no_places; i++) {
    free(place_table[i]);
}
free(place_table);
