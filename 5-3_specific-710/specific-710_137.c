#include <stdio.h>
#include <stdlib.h>

void get(char **string) {
    int size = 1;
    char c;
    int i = 0;

    *string = malloc(size);
    if (*string == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            break;
        }
        (*string)[i] = c;
        i++;
        char* temp = realloc(*string, size + 1);

        if (temp == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            free(*string);
            exit(EXIT_FAILURE);
        } else {
            *string = temp;
            size++;
        }
    }

    (*string)[i] = '\0';
}

int main() {
    char *buff = NULL;

    printf("String: ");
    get(&buff);
    printf("%s\n", buff);

    free(buff);

    return 0;
}
