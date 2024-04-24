#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buffer = malloc(1);
    int length = 0;
    int character;
    
    if (buffer == NULL) {
        printf("Error: Unable to allocate memory\n");
        return 1;
    }

    while ((character = getchar()) != EOF) {
        buffer[length] = character;
        length++;

        if ((length % 1000) == 0) {
            char *temp = realloc(buffer, length + 1);
            if (temp == NULL) {
                printf("Error: Out of memory!\n");
                free(buffer);
                return 1;
            }
            buffer = temp;
        }
    }

    buffer[length] = '\0';

    for (int i = length - 1; i >= 0; i--) {
        printf("%c", buffer[i]);
    }
    printf("\n");

    free(buffer);

    return 0;
}
