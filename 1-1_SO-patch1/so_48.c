    #define MAX_ENTRIES 100
    #define MAX_LINE_LEN 1024
    struct journal
    {
        int day;
        int month;
        int year;
        char entry[ MAX_LINE_LEN ];
    };
    typedef struct journal Diary;
    Diary myDiary[ MAX_ENTRIES ];
    char line[ MAX_LINE_LEN ];
    size_t i = 0;
    char *token = NULL;
    while( i < MAX_ENTRIES && fgets(day,1024,file) )
    {
        token=strtok(day,"/");
        if( token )
        {
            myDiary[i].day = atoi( token ); // is my day
            
            token=strtok(NULL,"/");
            if( token )
            {
                myDiary[i].month = atoi( token );
                token = strtok( NULL, "/" );
                if( token )
                {
                    myDiary[i].year = atoi( token );
                    fgets( myDiary[i].entry, MAX_LINE_LEN, file );
                }
            }
        }
        i++;
    }