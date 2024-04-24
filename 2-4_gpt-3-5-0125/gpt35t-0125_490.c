int copyText(char from[], char to[], int max)
{
    int i;
    if (new_strlen(from) <= max)
    {
        for(i = 0; from[i] != '\0'; i++) {
            to[i] = from[i];
        }
        to[i] = '\0';
    }
    return 0;
}
