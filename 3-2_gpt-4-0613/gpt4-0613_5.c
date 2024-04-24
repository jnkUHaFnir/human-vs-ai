// Reallocate first dimension
int **temp_place_table = realloc(place_table, (new_no_places + 1) * sizeof(int *));
if (temp_place_table == NULL) {
    // handle error
}
else {
    place_table = temp_place_table;
}

// Reallocate second dimension
for (i = 1; i <= new_no_places; i++) {
    int *temp_row = realloc(place_table[i], (new_no_places + 1) * sizeof(int));
    if (temp_row == NULL) {
        // handle error
    }
    else {
        place_table[i] = temp_row;
    }
}
