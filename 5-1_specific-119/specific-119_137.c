#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        *string = realloc(*string, ++size);
    }

    (*string)[i] = '\0';
}

int main() {
    char *buff = malloc(1); // Allocate memory
    printf("String: ");
    get(&buff); // Pass pointer to pointer
    printf("%s", buff);

    free(buff); // Free allocated memory
    return 0;
}
``` 

Note: It's important to free the allocated memory using `free()` to avoid memory leaks when you are done using it.
