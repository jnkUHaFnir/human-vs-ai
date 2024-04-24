    char* url;
    if ( fin ) 
    {
        while ( line = read_line(fin) ) 
        {
            if ( (url=strstr(line, "url="))!=NULL )
            {
                url = new char[strlen(line)+1]; //if you don't know why I'm adding +1 look up null terminated strings
                fprintf(stdout, "%s \n", url);
                strcpy(url, line);
            }
            free(line);
        }
    }