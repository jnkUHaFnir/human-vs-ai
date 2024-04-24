char *input(void)
{
    int n = 1;
    char *str = malloc(sizeof(char));
    *str = '\0';
    
    char *ptr = str; // Create a separate pointer to keep track of the original memory block
    
    int ch;
    while((ch=getchar())!='\n' && ch != EOF)
    {
        n++;
        str = realloc(str, sizeof(char) * n);
        if (str == NULL) {
            free(ptr); // Free the original memory block if realloc fails
            return NULL;
        }
        str[n-2] = (char)ch;
        str[n-1] = '\0';
    }
    
    return str;
}
