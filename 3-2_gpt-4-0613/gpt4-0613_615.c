#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reChar(char **, int *);
char * readLine(char **, int *);

int main() {
    char *palabra = NULL;
    int largo = 0;

    if (reChar(&palabra, &largo) == -1) {
        printf("error (re)allocating memory\n");
        return -1;
    }

    if ((palabra = readLine(&palabra, &largo)) == NULL) {
        free(palabra);
        printf("Error reading line\n");
        return -1;
    }
 
    printf("palabra=%s\n", palabra, largo);
    free(palabra);
    return 0;
}

int reChar(char **lst, int *largo) {
    (*largo) += 4;
    char *temp = (char*) realloc(*lst, (*largo) * sizeof (char));

    if (temp != NULL) {
        *lst = temp;
    } else {
        free(*lst);
        return -1;
    }
    return 0;
}

char * readLine(char **lst, int *largo) {
    int c;
    int pos = 0;

    c = getchar();
    while (c != '\n' && c != EOF) {
        if ((pos + 1) % 4 == 0) {
            if (reChar(lst, largo) == -1){
                return NULL;
            }
        }
        (*lst)[pos] =(char) c;
        pos++;
        c = getchar();
        if (c == EOF){
            printf("Unexpected end of file\n");
            return NULL;
        }
    }
    (*lst)[pos] = '\0';
    return *lst;
}
