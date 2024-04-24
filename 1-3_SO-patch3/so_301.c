    // copies src to dest and returns a pointer to the next available character in the dest buffer.
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