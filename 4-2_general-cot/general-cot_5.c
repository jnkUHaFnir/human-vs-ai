// Free the memory of the current 2D array
for(i = 1; i <= no_places; i++) {
    free(place_table[i]);
}
free(place_table);

// Update the size of the 2D array
place_table = (int **)malloc((new_no_places+1)*sizeof(int *));
for(i = 1; i <= new_no_places; i++) {
    place_table[i] = (int *)malloc((new_no_places+1)*sizeof(int));
}

// Initialize the elements of the new array if necessary
// You can copy the values from the old array to the new array if needed
