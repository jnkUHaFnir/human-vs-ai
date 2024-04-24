char *input(void)
{
    int n = 1;
    char *str = malloc(sizeof(char));
    *str = '\0';
    char *ptr = str;
    char c;
    while((c = getchar()) != '\n')
    {
        n++;
        ptr = realloc(str, sizeof(char) * n);
        if(ptr == NULL)
        {
            free(str);
            return NULL;
        }
        str = ptr;
        str[n-2] = c;
        str[n-1] = '\0';
    }
    return str;
}
