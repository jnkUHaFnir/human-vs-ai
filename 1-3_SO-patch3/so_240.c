    #define CHUNK_SIZE 4096
    char file_buffer[CHUNK_SIZE + 64] ;    // 4Kb buffer, plus enough 
                                           // for at least one one line
    int buffer_count = 0 ;
    int i = 0 ;
    
    while( i < cnt )
    {
        buffer_count += sprintf( &file_buffer[buffer_count], "%d %d %d\n", a[i], b[i], c[i] ) ;
        i++ ;
        
        // if the chunk is big enough, write it.
        if( buffer_count >= CHUNK_SIZE )
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