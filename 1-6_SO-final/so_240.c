    char file_buffer[4096 + 64] ;    // 4Kb buffer, plus enough 
                                     // for at least one one line
    int buffer_count = 0 ;
    int i = 0 ;
    
    while( i < cnt )
    {
        buffer_count += sprintf( line_buffer, "%d %d %d\n", a[i], b[i], c[i] ) ;
        
        // if the chunk is big enough, write it.
        if( buffer_count >= 4096 )
        {
            fwrite( file_buffer, 1, buffer_count, f ) ;
            buffer_count = 0 ;
        }
    }
    
    // Write remainder
    if( buffer_count > 0 )
    {
        fwrite( file_buffer, 1, buffer_count, f ) ;    
    }