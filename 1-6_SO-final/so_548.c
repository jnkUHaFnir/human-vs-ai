    char *directions[ 3 ];
    const MAX_LINE_SIZE = 256;
    char line[ MAX_LINE_SIZE ];
    for (size_t nstr = 0; nstr < 3; ++nstr) {
          fgets( line, MAX_LINE_SIZE, stdin );
          if (line[ 0 ] != 0) {
               directions[ nstr ] = malloc( strlen( line ) );
               strcpy( directions[ nstr ], line );
          }
          printf( "%s\n", directions[ nstr ] );
    }