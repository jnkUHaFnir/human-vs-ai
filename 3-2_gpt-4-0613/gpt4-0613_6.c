fin = fopen("file1.txt", "r");

char* url = NULL;
if (fin) 
{
    char *line;
    while ( (line = read_line(fin)) ) 
    {
        char* tempUrl = strstr(line, "url=");
        if (tempUrl != NULL )
        {
            fprintf(stdout, "%s \n", tempUrl);

            // release old url
            if (url != NULL) 
            {
                free(url);
            }
            
            // allocate new memory for the url
            url = malloc(strlen(tempUrl) + 1);
            
            // ensure memory allocation was successful 
            if (url != NULL) 
            {
                // copy the url
                strcpy(url, tempUrl);
            }
        }
        free(line);
    }
}

// Now the URL should still be available if it was found in the file.
if (url != NULL)
{
    printf("line is: %s\n", url);
    free(url); // After using it, don't forget to free the memory!
}

fclose(fin);
