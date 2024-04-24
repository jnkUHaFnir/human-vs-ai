char *input(void)
{
    int n = 1;
    char *str = malloc(sizeof(char));
    *str = '\0';
    char *temp = str; // Store the original pointer

    while((*temp = getchar()) != '\n')
    {
        n++;
        temp = realloc(str, sizeof(char) * n); // realloc to temp
        if (temp == NULL) {
            free(str); // Free original pointer before returning
            return NULL;
        }
        str = temp; // Update str to the newly allocated memory
        temp++; // Move to the next character in the string
    }
    return str;
}
