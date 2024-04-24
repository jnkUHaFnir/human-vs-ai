// Allocate memory for the initial 2D array
int **place_table = (int **)malloc((no_places+1)*sizeof(int *));
for(int i = 1; i <= no_places; i++) {
    place_table[i] = (int *)malloc((no_places+1)*sizeof(int));
}

// Increase size logic, for example increasing no_places by 1
int new_no_places = no_places + 1;

// Create a temporary array with the new size
int **temp_place_table = (int **)malloc((new_no_places+1)*sizeof(int *));
for(int i = 1; i <= new_no_places; i++) {
    temp_place_table[i] = (int *)malloc((new_no_places+1)*sizeof(int));
}

// Copy contents from the current array to the temporary array
for(int i = 1; i <= no_places; i++) {
    for(int j = 1; j <= no_places; j++) {
        temp_place_table[i][j] = place_table[i][j];
    }
}

// Deallocate memory for the current array
for(int i = 1; i <= no_places; i++) {
    free(place_table[i]);
}
free(place_table);

// Reallocate memory for the new size
place_table = temp_place_table;

// Update the size variable
no_places = new_no_places;

// Deallocate memory for the temporary array
free(temp_place_table);
