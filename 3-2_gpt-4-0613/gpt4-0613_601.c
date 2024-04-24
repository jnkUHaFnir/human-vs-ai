#include<stdio.h>
#include<stdlib.h>

char *input(void)
{
    int n = 1;
    char *str = malloc(sizeof(char));
    *str = '\0';
    char ch;
    while((ch=getchar())!='\n')
    {
        str = realloc(str, (n + 1) * sizeof(char));  // Reallocate memory.
        str[n-1] = ch;  // Add the character to the last allocated position.
        n++;
    }
    str[n-1] = '\0';  // Null-terminate the string.
    return str;
}

int main(int argc, char const *argv[])
{
    char *str = input();
    printf("%s",str);
    free(str);
    return 0;
}
