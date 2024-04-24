    char buffer[256];
    ...
    printf("Enter your name: ");
    if( 1 != scanf( " %255s", bufffer ) )
    {
         perror( " scanf for name failed" );
         cleanup();  // free all memory allocations
    }
    // implied else, scanf successful
    student_t[i].name = strdup(buffer);