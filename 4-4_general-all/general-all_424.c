#include <stdio.h>
#include <stdlib.h>

char* getString()
{
    char buffer;
    int size = 0;
    int capacity = 1;

    char* inputString = (char*)malloc(capacity * sizeof(char));
    if (inputString == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    while (1)
    {
        buffer = getchar();
        if (buffer == '\n' || buffer == EOF) {
            break;
        }

        // Check if we need to resize
        if (size == capacity - 1)
        {
            capacity *= 2;
            char* newString = (char*)realloc(inputString, capacity * sizeof(char));
            if (newString == NULL) {
                printf("Memory reallocation failed.\n");
                free(inputString);
                return NULL;
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
    
    if (str != NULL) {
        printf("%s", str);
        free(str); // Free the memory after use
    }

    return 0;
}
