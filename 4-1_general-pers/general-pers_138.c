#include <stdlib.h>
#include <stdio.h>

#define INITIAL_SIZE 10

void get(char **string) {
    int size = INITIAL_SIZE;
    int i = 0;    

    *string = (char *)malloc(size * sizeof(char));
    if (*string == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    int c;
    while ((c = getchar()) != EOF && c != '\n') {
        if (i == size - 1) {
            size *= 2;
            char *temp = (char *)realloc(*string, size * sizeof(char));
            if (temp == NULL) {
                fprintf(stderr, "Memory reallocation failed.\n");
                exit(1);
            }
            *string = temp;
        }
        (*string)[i++] = c;
    }
    (*string)[i] = '\0';
}

int main() {
    char *buff = NULL;

    printf("String: ");
    get(&buff);
    printf("Input: %s\n", buff);

    free(buff); // Free allocated memory

    return 0;
}
