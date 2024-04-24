#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reChar(char **lst, int *length);
void readLine(char **lst, int *length);

int main() {
    char *palabra = NULL;
    int length = 0;

    reChar(&palabra, &length);
    readLine(&palabra, &length);
    printf("palabra=%s\n", palabra);

    free(palabra); // Free the allocated memory
    return 0;
}

void reChar(char **lst, int *length) {
    (*length) += 2; // Increase the size by a reasonable amount
    char *temp = (char*)realloc(*lst, (*length) * sizeof(char));

    if (temp != NULL) {
        *lst = temp;
    } else {
        free(*lst);
        puts("Error reallocating memory");
        exit(1);
    }
}

void readLine(char **lst, int *length) {
    int c;
    int pos = 0;

    c = getchar();
    while (c != '\n' && c != EOF) {
        if (pos + 1 >= *length) {
            reChar(lst, length);
        }
        (*lst)[pos] = (char)c;
        pos++;
        c = getchar();
    }
    (*lst)[pos] = '\0';
}
