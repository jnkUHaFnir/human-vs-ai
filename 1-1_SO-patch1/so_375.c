    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #define MAXNAMELEN 1024
    // prototypes
    int compare(const void *, const void *);
    int main( void )
    {
        printf("Enter a source filename: ");
        char name[ MAXNAMELEN ];
        if( !fgets(name, sizeof( name ), stdin) )
        {
            perror( "fgets for input file name failed" );
            puts( name );
            exit( EXIT_FAILURE );
        }
        // implied else, fgets for input file name successful
        name[strcspn( name, "\n" ) ] = '\0'; // strip newline
        printf("%s infile \n",name);
        FILE *fp_in = fopen(name, "r");
        if( !fp_in )
        {
            perror( "fopen for input file failed" );
            exit( EXIT_FAILURE );
        }
        // implied else, fopen to read input file successful
        char **linesarray = NULL;
        size_t numLines   = 0;
        char   *line      = NULL;
        size_t  lineLen   = 0;
        while( getline( &line, &lineLen, fp_in ) != -1 )
        {
            char ** temp = realloc( linesarray, (numLines+1) * sizeof( char* ) );
            if( !temp )
            {
                perror( "realloc failed" );
                fclose( fp_in );
                for( size_t i = 0; i< numLines; i++ )
                {
                    free( linesarray[i]);
                }
                free( linesarray );
                exit( EXIT_FAILURE );
            }
            // implied else, realloc successful
            linesarray = temp;
            linesarray[ numLines ] = line;
            numLines++;
            // prep for next iteration
            line = NULL;
            lineLen = 0;
        }
        fclose( fp_in );
        //puts( "all file read in" );
        qsort( linesarray, numLines, sizeof( char * ), compare );
        //puts( "file sorted" );
        printf("Enter a destination filename: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn( name, "\n" ) ] = '\0'; // strip newline
        FILE *fp_out = fopen(name, "w");
        if( !fp_out )
        {
            perror( "fopen for output file failed" );
            for( size_t i = 0; i< numLines; i++ )
            {
                free( linesarray[i]);
            }
            free( linesarray );
            exit( EXIT_FAILURE );
        }
        // implied else, fopen for output file successful
        for (size_t i=0; i<numLines; i++)
        {
            if( fputs(linesarray[i], fp_out ) == EOF )
            {
                perror( "fputs failed" );
                fclose( fp_out );
                for( size_t i = 0; i< numLines; i++ )
                {
                    free( linesarray[i]);
                }
                free( linesarray );
                exit( EXIT_FAILURE );
            }
        }
        fclose( fp_out );
        for( size_t i = 0; i< numLines; i++ )
        {
            free( linesarray[i]);
        }
        free( linesarray );
    }
    int compare(const void *ls, const void *rs )
    {
        char *leftSide  = *(char**)ls;
        char *rightSide = *(char**)rs;
        return strcmp( leftSide, rightSide );
    }