fin = fopen("file1.txt", "r");

char* url;
if ( fin ) 
{
    while ( line = read_line(fin) ) 
    {
        if ( (url=strstr(line, "url="))!=NULL )
        {
            fprintf(stdout, "%s \n", url);
            url=strdup(url); // make a copy of the data
        }
        free(line);
    }
}

printf("line is:%s ",url);
fclose(fin);
