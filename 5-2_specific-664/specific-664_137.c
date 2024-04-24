#include <stdlib.h>
#include <stdio.h>

void get(char **string) {
    int size = 1;
    *string = malloc(size);
    char c;
    int i = 0;

    while(1) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            break;
        }
        (*string)[i] = c;
        i++;
        *string = realloc(*string, ++size);
    }

    (*string)[i] = '\0';
}

int main() {
    char *buff = NULL;

    printf("String: ");
    get(&buff);
    printf("%s\n", buff);

    free(buff); // Don't forget to free allocated memory

    return 0;
}
