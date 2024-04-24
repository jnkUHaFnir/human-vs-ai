fin = fopen("file1.txt", "r");

char* url = NULL;
if (fin) 
{
    while (line = read_line(fin)) 
    {
        if ((url = strstr(line, "url=")) != NULL)
        {
            fprintf(stdout, "%s \n", url);
            url = strdup(url); // Allocate memory and copy the data
        }
        free(line);
    }
}

printf("line is: %s", url); 
free(url); // Free the memory allocated by strdup
fclose(fin);
