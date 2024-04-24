char *input(void)
{
    int n = 1;
    char *str = malloc(sizeof(char));
    char *p = str;
    *str = '\0';
    while((*p=getchar())!='\n')
    {
        n++;
        str = realloc(str,sizeof(char)*n);
        p = str + n-2;
    }
    *(str+n-1) = '\0';
    return str;
}
