    // Assuming 512 bytes is enough
    
    size_t size = 512;
    char* dest = (char*) malloc( size );      // allow an extra byte for the null terminator
    memset( dest, 0, size );
    char* end = StringCopyEnd( dest, "Hello world", size );
    end = StringCopyEnd( end, ".  Good bye world", size - ( end - dest ) );
    printf( "%s", dest );