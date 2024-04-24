#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

char* getString() {
    char buffer[2];  // +1 for buffer and +1 for null terminator
    int size = 0;
    int capacity = INITIAL_CAPACITY;

    char* inputString = (char*)malloc(capacity * sizeof(char));
    if (inputString == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }

    while (1) {
        fgets(buffer, 2, stdin);

        if (buffer[0] == '\n') {
            break;
        }

        if (size >= capacity - 1) {
            capacity *= 2;
            char* newString = (char*)realloc(inputString, capacity * sizeof(char));
            if (newString == NULL) {
                printf("Memory reallocation failed");
                free(inputString);
                exit(1);
            }
            inputString = newString;
        }

        inputString[size] = buffer[0];
        size++;
    }

    inputString[size] = '\0';
    return inputString;
}

int main() {
    char* str;
    str = getString();
    printf("%s\n", str);
    free(str); // Free the dynamically allocated memory
    return 0;
}
