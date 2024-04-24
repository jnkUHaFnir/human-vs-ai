    int no_places;
    int n = no_places + 1;  // for brevity in the following statement
    int (*place_table)[n] = malloc(sizeof(int[n][n]));
    
    // check for NULL
    if(place_table == NULL) {
        // there's a problem
        // handle it
    }
    else {
        // you are good to go
    }