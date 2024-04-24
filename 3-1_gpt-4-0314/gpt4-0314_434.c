int **new_place_table = (int **)realloc(place_table, (new_no_places + 1) * sizeof(int *));
if (new_place_table == NULL) {
    // handle realloc error
    printf("Error reallocating memory.\n");
    exit(1);
}
place_table = new_place_table;
for (i = 1; i <= new_no_places; i++) {
    int *new_row = (int *)realloc(place_table[i], (new_no_places + 1) * sizeof(int));
    if (new_row == NULL) {
        // handle realloc error
        printf("Error reallocating memory for row %d.\n", i);
        exit(1);
    }
    place_table[i] = new_row;
}
for (i = no_places + 1; i <= new_no_places; i++) {
    place_table[i] = (int *)malloc((new_no_places + 1) * sizeof(int));
    if (place_table[i] == NULL) {
        // handle malloc error
        printf("Error allocating memory for row %d.\n", i);
        exit(1);
    }
}
no_places = new_no_places;
