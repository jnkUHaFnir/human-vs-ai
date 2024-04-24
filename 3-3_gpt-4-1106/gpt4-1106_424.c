#include <stdio.h>
#include <stdlib.h>

char* getString()
{
    char buffer;
    int size = 0;
    int capacity = 1;

    char* inputString = (char*)malloc(capacity * sizeof(char));
    if (inputString == NULL) {
        return NULL; // Handle malloc failure
    }

    while ((buffer = getchar()) != '\n' && buffer != EOF)
    {
        if ((size + 1) >= capacity)
        {
            capacity *= 2;
            inputString = realloc(inputString, capacity * sizeof(char));
            if (inputString == NULL) {
                return NULL; // Handle realloc failure
            }
        }
        inputString[size] = buffer;
        size++;
    }
    inputString[size] = '\0';
    
    return inputString;
}

// Your main function ...
