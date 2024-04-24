#include <stdio.h>
#include <stdlib.h>

char* getString() {
    char buffer;
    int size = 0;
    int capacity = 1;

    char* inputString = (char*)malloc(capacity * sizeof(char));

    while (1) {
        buffer = getchar();
        if (buffer == '\n')
            break;
        if (size >= capacity - 1) {
            capacity *= 2;
            char* newString = (char*)realloc(inputString, capacity * sizeof(char));
            inputString = newString;
        }
        inputString[size] = buffer;
        size++;
    }
    inputString[size] = '\0';
    return inputString;
}

int main() {
    char* str;
    str = getString();
    printf("%s", str);
    free(str);
    return 0;
}
