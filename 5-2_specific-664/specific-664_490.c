int copyText(char from[], char to[], int max)
{
    int i;
    if (new_strlen(from) <= max)
    {
        for (i = 0; from[i] != '\0'; i++)
        {
            to[i] = from[i];
        }
        to[i] = '\0'; // Add the null terminator at the end of the copied string
    }
    return 0;
}
