char *input(void)
{
    int n = 1;
    char *str = malloc(sizeof(char));
    *str = '\0';
    char *temp; // Create a temporary pointer to store the reallocated memory
    while((*str=getchar())!='\n')
    {
        n++;
        temp = realloc(str, sizeof(char)*n); // Assign the result of realloc() to temp
        if (temp == NULL) {
            free(str); // Free the original pointer before returning
            return NULL;
        }
        str = temp; // Update the original pointer with the reallocated memory
        str++;
    }
    return str;
}
