    // Assuming 512 bytes is enough
    char* dest = (char*) malloc( 512 );
    memset( dest, 0, 512 );
    char* end = strncpyend( dest, "Hello world", 512 );
    end = strncpyend( end, ".  Good bye world", 512 - ( end - dest ) );
    printf( "%s", dest );