#include <stdio.h>
#include <stdlib.h>

char* readUnlimitedInput() {
    char* input = NULL;
    char* temp = NULL;
    char c;
    size_t size = 0;
    size_t len = 0;

    do {
        c = getchar();
        if (c == '\n') {
            c = '\0';  // Replacing newline with null terminator
        }

        if (len + 1 >= size) {
            size += 10;
            temp = realloc(input, size * sizeof(char));
            if (temp == NULL) {
                free(input);
                return NULL; // Memory allocation error
            }
            input = temp;
        }

        input[len] = c;
        len++;
    } while (c != '\0');

    return input;
}

int main() {
    char* address = readUnlimitedInput();

    if (address != NULL) {
        printf("Address: %s\n", address);
        free(address);
    } else {
        printf("Error reading address.\n");
    }

    return 0;
}
