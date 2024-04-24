    int intAskUser(void)
    {
        // Variable Declarations
        char cInput = 0 ;
        int nAnswer = -1 ;
    
        // Code starts here ......
        while( answer < 0 )
        {
            printf("Do you want to enter a value? Y or N\n");
            scanf("%c", &cInput ) ;
            while( cInout != '\n' && getchar() != '\n' ) { } // flush buffered line 
    
            if( toupper(cInput) == 'Y' )
            {
                nAnswer = 1;
            }
            else if( toupper( cInput ) == 'N' )
            {
                nAnswer = 0;
            }
        }
    
        return nAnswer;
    }
    
    int getValue(int nLower, int nUpper)
    {
        // Variable Declarations
        static int nValue = nLower - 1; 
    
        // Code starts here ......
        while( nValue < nLower || nValue > nUpper )
        {
            printf("Enter a value between %d and %d: ", nLower, nUpper ) ;
            scanf("%d", &nValue);
            while( getchar() != '\n' ) { } // flush buffered line 
    
            if( nValue < nLower || nValue > nUpper )
            {
                printf( "Please try again. );
            }
        }
    
        printf("Value: %d", nValue);
        return nValue;
    }