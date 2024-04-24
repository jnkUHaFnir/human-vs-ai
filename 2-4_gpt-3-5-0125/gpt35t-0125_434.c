int **new_place_table = (int **)realloc(place_table, (new_no_places+1)*sizeof(int *));

if (new_place_table != NULL) {
    place_table = new_place_table;

    for (i = 1; i <= new_no_places; i++) {
        place_table[i] = (int *)realloc(place_table[i], (new_no_places+1)*sizeof(int));
    }

    // update no_places to new_no_places
    no_places = new_no_places;
} else {
    // handle error if realloc fails
}
