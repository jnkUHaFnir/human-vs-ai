    scanf("%c", &cInput ) ;
    if( cInput != '\n' && getchar() != '\n' )
    {
        while( getchar() != '\n' ) { } // flush buffered 
        cInput = `\n` ;
    }
     