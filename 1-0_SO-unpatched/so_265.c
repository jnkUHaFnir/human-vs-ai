    char buffer[256];
    ...
    printf("Enter your name: ");
    if ( 1 != scanf( " %255s", buffer ) )
    {
         perror( " scanf for name failed" );
         cleanup();  // free all memory allocations
         exit(1);
    }
    // implied else, scanf successful
    student_t[i].name = strdup(buffer);