// Assume new_no_places is the new size of the 2D array

// Step 1: Allocate a new temporary 2D array
int** new_place_table = (int **)malloc((new_no_places + 1) * sizeof(int *));
for (i = 1; i <= new_no_places; i++) {
    new_place_table[i] = (int *)malloc((new_no_places + 1) * sizeof(int));
}

// Step 2: Copy existing data to the new array
int min_no_places = (new_no_places < no_places) ? new_no_places : no_places;
for (i = 1; i <= min_no_places; i++) {
    for (j = 1; j <= min_no_places; j++) {
        new_place_table[i][j] = place_table[i][j];
    }
}

// Step 3: Free memory associated with the old array
for (i = 1; i <= no_places; i++) {
    free(place_table[i]);
}
free(place_table);

// Step 4: Update the pointer to point to the new array
place_table = new_place_table;
