    // Assuming 512 bytes is enough
    
    size_t size = 512;
    char* dest = (char*) malloc( size + 1 );      // allow an extra byte for the null terminator
    memset( dest, 0, size + 1 );
    char* end = strncpyend( dest, "Hello world", size );
    end = strncpyend( end, ".  Good bye world", size - ( end - dest ) );
    printf( "%s", dest );