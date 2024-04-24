    #define CHUNK_SIZE 4096
    char file_buffer[CHUNK_SIZE + 64] ;
    int buffer_count = 0 ;
    int i = 0 ;
    
    while( i < cnt )
    {
        buffer_count += sprintf( line_buffer, "%d %d %d\n", a[i], b[i], c[i] ) ;
        i++ ;
        
        // if the chunk is big enough, write it.
        if( buffer_count >= 4096 )
        {
            fwrite( file_buffer, 1, CHUNK_SIZE, f ) ;
            buffer_count -= CHUNK_SIZE ;
            memcpy( file_buffer, &file_buffer[CHUNK_SIZE], buffer_count ) ;
        }
    }
    
    // Write remainder
    if( buffer_count > 0 )
    {
        fwrite( file_buffer, 1, buffer_count, f ) ;    
    }