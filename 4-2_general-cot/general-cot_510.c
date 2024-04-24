#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buffer = malloc(1);
    int length = 0;
    int character;

    if (buffer == NULL) {
        printf("Error: Out of memory!\n");
        return 1;
    }

    for (length = 0; (character = getchar()) != EOF; length++) {
        buffer[length] = (char) character;
        if ((length == 0) || ((length % 1000) == 0)) {
            char *temporary = realloc(buffer, length + 1001);
            if (temporary != NULL) {
                buffer = temporary;
            } else {
                printf("Error: Out of memory!\n");
                free(buffer);
                return 1;
            }
        }
    }

    buffer[length] = '\0';
    length--;

    while (length >= 0) {
        printf("%c”, buffer[length]);
        length--;
    }

    printf("\n");
    free(buffer);

    return 0;
}
