#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 16

char* getString()
{
    char buffer;
    int size = 0;
    int capacity = INITIAL_CAPACITY;

    char* inputString = (char*)malloc(capacity * sizeof(char));

    while(1)
    {
        buffer = getchar();
        if(buffer == '\n' || buffer == EOF)
            break;
        if(size >= capacity - 1)
        {
            capacity *= 2;
            inputString = (char*)realloc(inputString, capacity * sizeof(char));
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
    free(str); // Remember to free the allocated memory
    return 0;
}
