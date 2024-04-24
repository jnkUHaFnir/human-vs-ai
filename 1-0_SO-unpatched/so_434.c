    int old_n = n;
    // value of n has been changed
    // allocate a new array
    int (*new_place_table)[n] = malloc(sizeof(int[n][n]));
    
    // check for NULL and accordingly proceed
    // if not NULL, copy place_table to new_place_table
 
    for(int i = 0; i < old_n; i++) {
        for(int j = 0; j < old_n; j++) {
            new_place_table[i][j] = place_table[i][j];
        }
    }
    
    free(place_table);
    // do stuff with new_place_table
    free(new_place_table); 