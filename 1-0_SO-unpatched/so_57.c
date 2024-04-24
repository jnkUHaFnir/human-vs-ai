    void hello( int depth )
    {
        printf( "hello %2d\n", depth );
        if ( depth > 1 )
            hello( depth - 1 );
    }
    
    int main()
    {
        int count;
        for (;;)
        {
            printf( "how many times do you want run the function? " );
            if ( scanf( "%d", &count ) != 1 || count == 0 )
                break;
    
            hello( count );
        }
    }