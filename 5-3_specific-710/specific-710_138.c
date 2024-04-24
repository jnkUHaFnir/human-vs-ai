#include <stdlib.h>
#include <stdio.h>

void get(char *string, size_t size) {
    char c;
    size_t i = 0;    

    while (1) {
        c = getchar();
        if (c == '\n' || i == size - 1) {
            break;
        }
        string[i] = c;
        i++;
    }
    string[i] = '\0';
}

int main() {
    size_t size = 64; // Initial size of the string
    char *buff = malloc(size * sizeof(char));

    if (buff == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("String: ");
    get(buff, size);
    printf("%s\n", buff);

    free(buff); // Don't forget to free allocated memory

    return 0;
}
