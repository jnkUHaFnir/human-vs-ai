    scanf("%c", &cInput ) ;   // Get a single character
    if( cInput != '\n' &&     // If the input is not "empty",
        getchar() != '\n' )   // but the first character entered was not
                              // immediately followed by a newline...
    {
        // Flush to the end of the entered line
        while( getchar() != '\n' ) { }
        // Invalidate the input to force retry
        cInput = `\n` ;
    }