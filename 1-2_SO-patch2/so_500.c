`
FILE* upcase (const char* path)
{
    int c, cnt = 0, i = 0, j = 1;
    int n = 500;
    FILE* fp = fopen(path, "r+");
    char* buffer = calloc(n, sizeof(char));
    if (!fp || !buffer)
    {
       return NULL;
    }
    while ((c = fgetc(fp)) != EOF)
    {  
       if ( i == n )
       {
           j++;
           realloc(buffer, sizeof(char) * (n * j);
           i = 0;
       }  
       c = toupper(c);
       buffer[i] = c;
       i++;
       cnt++;
    }
   
    for ( int i = 0; i < cnt; i++ )
    {
        if (fputc(c, fp) == EOF)
        {
            return NULL;
        }
    }
    return fp;    
}
`