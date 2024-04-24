char *input(void)
{
    int n = 1;
    char *str = malloc(sizeof(char));
    *str = '\0';
    char c;
    
    while((c = getchar()) != '\n')
    {
        n++;
        str = realloc(str, sizeof(char) * n);
        str[n-2] = c;
        str[n-1] = '\0';
    }
    return str;
}
