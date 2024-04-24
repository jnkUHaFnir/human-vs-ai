#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reChar(char **, int *);
void readLine(char **, int *);

int main() {
    char *palabra = NULL;
    int largo = 0;

    reChar(&palabra, &largo);
    readLine(&palabra, &largo);
    printf("palabra=%s\n", palabra, largo);

    printf("Press Enter to continue...\n");
    getchar();
    return 0;
}

void reChar(char **lst, int *largo) {
    *largo *= 2; // double the size
    char *temp = (char*) realloc(*lst, *largo * sizeof (char));

    if (temp != NULL) {
        *lst = temp;
    } else {
        free(*lst);
        puts("Error: failed to (re)allocate memory");
        exit(1);
    }
}

void readLine(char **lst, int *largo) {
    int c;
    int pos = 0;

    c = getchar();
    while (c != '\n' && c != EOF) {
        if (pos == *largo) { // check if pos is equal to largo
            reChar(lst, largo);
        }
        (*lst)[pos] = (char) c;
        pos++;
        c = getchar();
    }
    (*lst)[pos] = '\0';
}
