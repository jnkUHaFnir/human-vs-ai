#include <stdlib.h>
#include <stdio.h>

void get(char **string) {
    int size = 1;
    *string = (char*)malloc(sizeof(char) * size);
    char c;
    int i = 0;

    while (1) {
        c = getchar();
        if (c == '\n') { break; }
        (*string)[i] = c;
        i++;
        *string = (char*)realloc(*string, sizeof(char) * (++size));
    }

    (*string)[i] = '\0';
}

int main() {
    char *buff = NULL;

    printf("String: ");
    get(&buff);
    printf("%s", buff);

    free(buff); // free allocated memory

    return 0;
}
