fin = fopen("file1.txt", "r");

char* url = NULL;
if ( fin ) 
{
    while (char* line = read_line(fin)) 
    {
        char* temp_line = line;

        if ( (url = strstr(line, "url=")) != NULL )
        {
            url = strdup(url); // Make a copy of the data
            fprintf(stdout, "%s \n", url);
        }

        free(temp_line);
    }
}

if (url) {
    printf("line is:%s\n", url);
    free(url); // Free the duplicated data
}

fclose(fin);
