void get(char **string) {
    int size = 1;
    *string = malloc(size);
    char c;
    int i = 0;

    while ((c = getchar()) != '\n' && c != EOF) {
        (*string)[i++] = c;
        *string = realloc(*string, ++size);
    }

    (*string)[i] = '\0';
}
get(&buff);
#include <stdlib.h>
#include <stdio.h>

void get(char **string) {
    int size = 1;
    *string = malloc(size);
    char c;
    int i = 0;

    while ((c = getchar()) != '\n' && c != EOF) {
        (*string)[i++] = c;
        *string = realloc(*string, i + 1);
    }

    (*string)[i] = '\0';
}

int main() {
    char *buff = NULL;

    printf("String : ");
    get(&buff);
    printf("%s\n", buff);

    free(buff); // Remember to free the allocated memory to avoid memory leaks

    return 0;
}
