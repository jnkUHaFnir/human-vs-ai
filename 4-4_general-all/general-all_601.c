#include <stdio.h>
#include <stdlib.h>

char *input(void)
{
    int n = 1;
    char *str = malloc(sizeof(char));
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed");
        exit(1);
    }
    *str = '\0';
    
    char *current = str;
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        n++;
        char *temp = realloc(str, sizeof(char) * n);
        if (temp == NULL) {
            fprintf(stderr, "Memory reallocation failed");
            free(str);
            exit(1);
        }
        str = temp;
        *current++ = c;
        *current = '\0'; // Null-terminate the string
    }
    
    return str;
}

int main(void)
{
    char *str = input();
    printf("%s\n", str);
    free(str);
    
    return 0;
}
