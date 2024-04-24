    #define YY_INPUT( BUF, RESULT, MAX_SIZE ) \
      (RESULT) = lexer_input( (BUF), (MAX_SIZE) )
    static size_t   my_col;          // current 0-based column number
    static char    *my_line[2];      // [0] is original line
    static size_t lexer_input( char *buf, size_t buf_size ) {
      static size_t capacity[2];
      char **const pline = &my_line[ !my_col ];
      size_t *const pcap = &capacity[ !my_col ];
      ssize_t const bytes_read = getline( pline, pcap, yyin );
      if ( bytes_read == -1 ) {
        if ( ferror( yyin ) )
          /* complain and exit */;
        return 0;
      }
      strncpy( buf, *pline, buf_size );
      return (size_t)bytes_read;
    }