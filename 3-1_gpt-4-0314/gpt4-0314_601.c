char *input(void)
{
    int n = 1, idx = 0;
    char *str = malloc(sizeof(char));
    *str = '\0';
    while((str[idx]=getchar())!='\n')
    {
        n++;
        idx++;
        str = realloc(str, n * sizeof(char));
    }
    str[idx] = '\0';
    return str;
}
int main(int argc, char const *argv[])
{
    char *str = input();
    printf("%s",str);
    free(str);
    return 0;
}
