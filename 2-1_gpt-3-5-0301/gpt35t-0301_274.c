memcpy(newString, inputString, size * sizeof(char));
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getString()
{
    char buffer;
    int size = 0;
    int capacity = 1;

    char* inputString = (char*)malloc(capacity*sizeof(char));
    char* newString;

    while(1)
    {
        buffer = getchar();
        if(buffer == '\n')
            break;
        if((capacity-1) <= size)
        {
            capacity *= 2;
            newString = (char*)malloc(capacity*sizeof(char));
            memcpy(newString, inputString, size * sizeof(char));
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
