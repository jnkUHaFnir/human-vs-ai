#include <stdlib.h>
#include <stdio.h>

void get(char **string) {
    int size = 1;
    *string = (char *)malloc(size * sizeof(char));
    if (*string == NULL) {
        // Handle memory allocation failure
        exit(1);
    }
    
    char c;
    int i = 0;    

    while (1) {
        c = getchar();
        if (c == '\n') {
            break;
        }
        
        (*string)[i] = c;
        i++;
        *string = (char *)realloc(*string, (size + 1) * sizeof(char));
        size++;
        if (*string == NULL) {
            // Handle memory allocation failure
            exit(1);
        }
    }

    (*string)[i] = '\0';
}

int main() {
    char *buff = NULL;

    printf("String: ");
    get(&buff);
    printf("Input string: %s\n", buff);

    free(buff); // Free allocated memory

    return 0;
}
