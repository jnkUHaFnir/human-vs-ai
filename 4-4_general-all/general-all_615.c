#include <stdio.h>
#include <stdlib.h>

void reChar(char **lst, int *largo);
void readLine(char **lst, int *largo);

int main() {
    char *palabra = NULL;
    int largo = 0;

    reChar(&palabra, &largo);
    readLine(&palabra, &largo);
    printf("palabra=%s\n", palabra);

    free(palabra); // Free the allocated memory before exiting
    return 0;
}

void reChar(char **lst, int *largo) {
    *largo += 4;
    char *temp = (char*)realloc(*lst, (*largo) * sizeof(char));
    
    if (temp != NULL) {
        *lst = temp;
    } else {
        free(*lst);
        puts("Error (re)allocating memory");
        exit(1);
    }
}

void readLine(char **lst, int *largo) {
    int c;
    int pos = 0;

    c = getchar();
    while (c != '\n' && c != EOF) {
        if ((pos + 1) % 4 == 0) {
            reChar(lst, largo);
        }
        (*lst)[pos] = (char)c;
        pos++;
        c = getchar();
    }
    (*lst)[pos] = '\0';
}
