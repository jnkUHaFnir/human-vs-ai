fin = fopen("file1.txt", "r");

char* url = NULL;
if (fin) 
{
    char* line;
    while ((line = read_line(fin))) 
    {
        if ((url = strstr(line, "url=")) != NULL)
        {
            url = strdup(url); // Create a duplicate copy of the url data
            fprintf(stdout, "%s \n", url);
        }
        free(line);
    }
}

printf("line is:%s ", url);
free(url); // Remember to free the duplicated url data
fclose(fin);
