    // copies src to dest and returns a pointer to the next available
    // character in the dest buffer.
    // Note that this will NOT terminate the dest.  You must do it 
    // when all string concatenation is complete.
    char* strncpyend( char* dest, char* src, size_t size )
    {
        size_t pos = 0;
        while ( pos < size && *src )
        {
            *dest = *src;
            ++dest;
            ++src;
        }
        return dest;
    }