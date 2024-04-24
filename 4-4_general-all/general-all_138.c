#include <stdio.h>
#include <stdlib.h>

void get(char **string) {
    int size = 1;
    *string = malloc(size);
    char c;
    int i = 0;
    
    while (1) {
        c = getchar();
        if (c == '\n') {
            break;
        }
        (*string)[i] = c;
        i++;
        *string = realloc(*string, i + 1);
    }
    
    (*string)[i] = '\0';
}

int main() {
    char *buff = NULL;

    printf("String: ");
    get(&buff);
    printf("%s\n", buff);

    free(buff); // Free the dynamically allocated memory

    return 0;
}
