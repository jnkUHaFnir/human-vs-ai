#include <stdio.h>
#include <stdlib.h>

char* getString()
{
    char buffer;
    int size = 0;
    int capacity = 1;

    char* inputString = (char*)malloc(capacity * sizeof(char));
    char* newString;

    if (!inputString) {
        printf("Memory allocation failed!");
        exit(1);
    }

    while (1)
    {
        buffer = getchar();
        if (buffer == '\n')
            break;
        if ((capacity - 1) <= size)
        {
            capacity *= 2;
            newString = (char*)realloc(inputString, capacity * sizeof(char));
            if (!newString) {
                printf("Memory allocation failed!");
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

int main()
{
    char* str;
    str = getString();
    printf("%s", str);
    free(str);
    return 0;
}
