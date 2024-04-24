#include <stdio.h>
#include <stdlib.h>

char *input(void)
{
    int n = 1;
    char *str = malloc(sizeof(char));
    if (str == NULL) {
        return NULL; // Check if malloc failed
    }
    *str = '\0';

    char *current = str;
    int ch;

    while((ch = getchar()) != '\n' && ch != EOF)
    {
        n++;
        char *temp = realloc(str, sizeof(char) * n);
        if (temp == NULL) {
            free(str);
            return NULL; // Check if realloc failed
        }
        str = temp;
        *current++ = ch;
        *current = '\0';
    }

    return str;
}

int main(int argc, char const *argv[])
{
    char *str = input();
    if (str == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("%s", str);
    free(str);
    return 0;
}
