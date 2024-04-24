    // Copies src to dest and returns a pointer to the next available
    // character in the dest buffer.
    // Ensures that a null terminator is at the end of dest.  If
    // src is larger than size then size - 1 bytes are copied
    char* StringCopyEnd( char* dest, char* src, size_t size )
    {
        size_t pos = 0;
        if ( size == 0 ) return dest;
  
        while ( pos < size - 1 && *src )
        {
            *dest = *src;
            ++dest;
            ++src;
            ++pos;
        }
        if ( pos < size ) 
        {
            *dest = '\0';
        }
        return dest;
    }