    int main()
    {
        printf( "Enter string: " );
        String str = String__getLine();
        printf( "You entered: '%s'\n", str.native );
    
        return EXIT_SUCCESS;
    }