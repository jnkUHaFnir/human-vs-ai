#include <stdio.h>
#include <stdlib.h>

void reChar(char **lst, int *size) {
    *size *= 2;
    char *temp = (char*)realloc(*lst, (*size) * sizeof(char));

    if (temp != NULL) {
        *lst = temp;
    } else {
        free(*lst);
        puts("Error reallocating memory");
        exit(1);
    }
}

void readLine(char **lst, int *size) {
    int c;
    int pos = 0;

    c = getchar();
    while (c != '\n' && c != EOF) {
        if (pos + 1 >= *size) {
            reChar(lst, size);
        }
        (*lst)[pos] = (char)c;
        pos++;
        c = getchar();
    }
    (*lst)[pos] = '\0';
}

int main() {
    char *palabra = NULL;
    int size = 4; // Initial size

    palabra = (char*)malloc(size * sizeof(char));
    if (palabra == NULL) {
        puts("Memory allocation failed");
        return 1;
    }

    readLine(&palabra, &size);

    printf("palabra=%s\n", palabra);

    free(palabra); // Free allocated memory

    return 0;
}
