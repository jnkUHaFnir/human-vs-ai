    int i;
    numbers = malloc( N*sizeof(int *) );        // N is the number of the rows
    for (i = 0 ; i < N ; i++)
        table[i] = malloc( M*sizeof(int) );     // M is the number of the rows