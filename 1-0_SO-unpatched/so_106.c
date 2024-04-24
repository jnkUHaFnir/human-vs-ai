    void testStringCopyEnd( char* str1, char* str2, size_t size )
    {
        // Create an oversized buffer and fill it with A's so that 
        // if a string is not null terminated it will be obvious.
        char* dest = (char*) malloc( size + 10 ); 
        memset( dest, 'A', size + 10 );
        char* end = StringCopyEnd( dest, str1, size );
        end = StringCopyEnd( end, str2, size - ( end - dest ) );
        printf( "length:  %d - '%s'\n", strlen( dest ), dest );
    }
    int main(int argc, _TCHAR* argv[])
    {
        // Test with a large enough buffer size to concatenate 'Hello World'.
        // and then reduce the buffer size from there
        for ( int i = 12; i > 0; --i )
        {
            testStringCopyEnd( "Hello", " World", i );
        }
        return 0;
    }