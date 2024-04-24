#include <stdio.h>
#include <stdlib.h> // Include this header for malloc and realloc

char* getString()
{
    char buffer;
    int size = 0;
    int capacity = 1;

    char* inputString = (char*)malloc(capacity*sizeof(char));

    while(1)
    {
        buffer = getchar();
        if(buffer == '\n')
            break;
        if((capacity-1) <= size)
        {
            capacity *= 2;
            inputString = (char*)realloc(inputString, capacity*sizeof(char));
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
    free(str); // Don't forget to free the dynamically allocated memory
    return 0;
}
