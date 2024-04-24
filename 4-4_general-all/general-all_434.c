// Assuming place_table is the existing 2D array
int new_no_places = new_size; // New size for the 2D array
int **new_place_table = (int **)malloc((new_no_places + 1) * sizeof(int *));

for (i = 1; i <= new_no_places; i++) {
    new_place_table[i] = (int *)malloc((new_no_places + 1) * sizeof(int));
}

// Copy data from the existing array to the new array
for (i = 1; i <= (no_places < new_no_places ? no_places : new_no_places); i++) {
    for (j = 1; j <= (no_places < new_no_places ? no_places : new_no_places); j++) {
        new_place_table[i][j] = place_table[i][j];
    }
}

// Free memory occupied by the existing array
for (i = 1; i <= no_places; i++) {
    free(place_table[i]);
}
free(place_table);

// Point place_table to the new array
place_table = new_place_table;
no_places = new_no_places; // Update no_places to the new size
