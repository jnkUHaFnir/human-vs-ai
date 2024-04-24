fin = fopen("file1.txt", "r");
char* url = NULL;

if ( fin ) 
{
    char *line;
    while ( (line = read_line(fin)) ) 
    {
        if ( (url=strstr(line, "url="))!=NULL )
        {
            fprintf(stdout, "%s \n", url);
            url=strdup(line); // make a copy of the data
            break; // exit the loop if url is found
        }
        free(line);
    }
}

if (url) {
    printf("line is:%s ",url); 
    free(url); // free the copied memory after its use
} else {
    printf("url not found\n");
}

fclose(fin);
