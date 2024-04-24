char *input(void)
{
    int n = 1;
    char *str = malloc(sizeof(char));
    *str = '\0';
    char *temp = str; // Store the original pointer

    int c;
    while((c = getchar()) != '\n' && c != EOF)
    {
        n++;
        str = realloc(str, sizeof(char) * n);
        *(temp+n-1) = c; // Save the character instead of incrementing the pointer
        *(temp+n) = '\0'; // Add null terminator
    }
    return temp;
}
