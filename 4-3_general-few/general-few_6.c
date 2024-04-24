fin = fopen("file1.txt", "r");

char* url = NULL;
char* line = NULL;

if ( fin ) 
{
    while ( (line = read_line(fin)) != NULL ) 
    {
        if ( (url = strstr(line, "url=")) != NULL )
        {
            fprintf(stdout, "%s \n", url);
            url = strdup(url); // Make a copy of the data
        }
        free(line);
    }
}

printf("line is: %s\n", url); 
free(url); // Don't forget to free the memory allocated by strdup
fclose(fin);
