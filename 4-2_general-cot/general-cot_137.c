#include <stdlib.h>
#include <stdio.h>

void get(char **string) {
    int size = 1;
    *string = (char*)malloc(size * sizeof(char));
    char c;
    int i = 0;

    if (*string == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    while (1) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            break;
        }
        (*string)[i] = c;
        i++;
        *string = (char*)realloc(*string, ++size * sizeof(char));

        if (*string == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }

    (*string)[i] = '\0';
}

int main() {
    char *buff = NULL;

    printf("String: ");
    get(&buff);
    printf("%s\n", buff);

    free(buff); // free the allocated memory

    return 0;
}
