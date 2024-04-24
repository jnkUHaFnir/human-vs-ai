#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void get(char ** string) {
    int size = 1;
    *string = malloc(size);
    char c;
    int i = 0;
    
    if (*string == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    while (1) {
        c = getchar();
        if (c == '\n') {
            break;
        }
        (*string)[i] = c;
        i++;
        *string = realloc(*string, i + 1);
        if (*string == NULL) {
            printf("Memory reallocation failed.\n");
            return;
        }
    }

    (*string)[i] = '\0';
}

int main() {
    char *buff = NULL;

    printf("String: ");
    get(&buff);
    printf("Entered string: %s\n", buff);

    free(buff);

    return 0;
}
