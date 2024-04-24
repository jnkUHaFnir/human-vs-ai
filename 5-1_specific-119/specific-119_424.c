#include <stdio.h>
#include <stdlib.h>

char* getString()
{
    char* inputString = NULL;
    char buffer;
    int size = 0;
    int capacity = 1;

    inputString = (char*)malloc(capacity * sizeof(char));
    if (inputString == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    while (1)
    {
        buffer = getchar();
        if (buffer == '\n') {
            inputString[size] = '\0';
            break;
        }

        if (size >= capacity - 1) { // Check if size exceeds capacity
            capacity *= 2;
            char* newString = (char*)realloc(inputString, capacity * sizeof(char));
            if (newString == NULL) {
                printf("Memory allocation error\n");
                exit(1);
            }
            inputString = newString;
        }

        inputString[size] = buffer;
        size++;
    }

    return inputString;
}

int main()
{
    char* str;
    str = getString();
    printf("%s", str);

    free(str); // Free the dynamically allocated memory when done using it

    return 0;
}
