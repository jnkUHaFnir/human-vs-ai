// Update no_places with the new value
int new_no_places = 10; // Set your new size here

// Reallocate memory for the outer array (place_table)
int **new_place_table = (int **)realloc(place_table, (new_no_places + 1) * sizeof(int *));
if (new_place_table == NULL) {
    printf("Error: Failed to reallocate memory for the outer array (place_table)\n");
    exit(1);
}
place_table = new_place_table;

// Reallocate memory for each of the inner arrays (place_table[i])
for (int i = 1; i <= new_no_places; i++) {
    int *temp = (int *)realloc(place_table[i], (new_no_places + 1) * sizeof(int));
    if (temp == NULL) {
      printf("Error: Failed to reallocate memory for inner array at index %d\n", i);
      exit(1);
    }
    place_table[i] = temp;
}

// Set no_places to the new value
no_places = new_no_places;
for (int i = 1; i <= no_places; i++) {
    free(place_table[i]);
}
free(place_table);
