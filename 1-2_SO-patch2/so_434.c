    // value of n has been changed
    // reallocate memory
    place_table = realloc(place_table, sizeof(int[n][n]));
    // access elements of the 2-D array
    for(int i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            // do something with place_table[i][j]
        }
    }
    // free the memory after you are done with place_table
    free(free_table); 