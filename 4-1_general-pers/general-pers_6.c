fin = fopen("file1.txt", "r");

char* url = NULL;
if ( fin ) 
{
    while ( char* line = read_line(fin) ) 
    {
        if ( (url=strstr(line, "url=")) != NULL )
        {
            url = strdup(url); // Make a copy of the data
            if (url)
            {
                fprintf(stdout, "%s \n", url);
                free(url); // Remember to free the copy when done with it
            }
        }
        free(line);
    }
}

fclose(fin);
