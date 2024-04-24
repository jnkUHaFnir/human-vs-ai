#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getString() {
    int size = 0;
    int capacity = 1;
    char* inputString = (char*)malloc(capacity * sizeof(char));

    if (inputString == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }

    char buffer;
    while (1) {
        buffer = getchar();
        if (buffer == '\n' || buffer == EOF)
            break;

        if (size + 1 >= capacity) {
            capacity *= 2;
            char* newString = (char*)realloc(inputString, capacity * sizeof(char));

            if (newString == NULL) {
                printf("Memory reallocation failed. Exiting.\n");
                free(inputString);
                exit(1);
            }

            inputString = newString;
        }

        inputString[size] = buffer;
        size++;
    }
    inputString[size] = '\0';

    return inputString;
}

int main() {
    char* str = getString();
    printf("%s\n", str);
    free(str);
    
    return 0;
}
