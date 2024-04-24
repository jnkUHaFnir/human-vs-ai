char *input(void)
{
    int n = 1;
    char *str = malloc(sizeof(char));
    str[0] = '\0';
    char *temp = str;
    while((*temp=getchar())!='\n')
    {
        n++;
        str = realloc(str,sizeof(char)*n);
        temp = str + n - 1;
    }
    return str;
}
