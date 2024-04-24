#include <stdio.h>
#include <stdlib.h>

void get(char **string) {
    int size = 1;
    *string = (char *)malloc(size * sizeof(char));
    if (*string == NULL) {
        printf("Memory allocation failed");
        return;
    }

    char c;
    int i = 0;

    while (1) {
        c = getchar();
        if (c == '\n') {
            break;
        }
        (*string)[i] = c;
        i++;
        *string = (char *)realloc(*string, (size + 1) * sizeof(char));
        if (*string == NULL) {
            printf("Memory allocation failed");
            return;
        }
    }

    (*string)[i] = '\0';
}

int main() {
    char *buff = NULL;

    printf("String: ");
    get(&buff);
    if (buff != NULL) {
        printf("Input string: %s\n", buff);
        free(buff); // Don't forget to free the memory when done
    }

    return 0;
}
