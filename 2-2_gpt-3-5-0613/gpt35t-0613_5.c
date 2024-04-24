// Allocate initial memory for the 2D array
place_table = (int **)malloc((no_places+1) * sizeof(int *));
for (i = 1; i <= no_places; i++)
    place_table[i] = (int *)malloc((no_places+1) * sizeof(int));

// Reallocate memory for the 2D array with a new size
int new_size = new_no_places + 1;
int** new_place_table = (int **)realloc(place_table, new_size * sizeof(int *));
if (new_place_table == NULL) {
    // Handle the case where reallocation failed
    // for example, print an error message and exit the program
    printf("Memory reallocation failed!\n");
    exit(1);
}

// Copy the elements from the old array to the new array
for (i = 1; i <= no_places; i++) {
    for (j = 1; j <= no_places; j++) {
        new_place_table[i][j] = place_table[i][j];
    }
}

// Update the size variables accordingly
no_places = new_no_places;
place_table = new_place_table;

// Free the old memory
for (i = 1; i <= no_places; i++) {
    free(place_table[i]);
}
free(place_table);
