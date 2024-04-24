#include <stdio.h>
#include <stdlib.h>

char* getString()
{
    char buffer;
    int size = 0;
    int capacity = 1;

    char* inputString = malloc(capacity*sizeof(char));

    if(inputString == NULL) { /* handle malloc failure */ }

    while(1)
    {
        buffer = getchar();
        if(buffer == '\n')
            break;
        if((capacity-1) <= size)
        {
            capacity *= 2;
            char* newString = realloc(inputString, capacity*sizeof(char));

            if(newString == NULL) { /* handle realloc failure */ }

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
    char* str = getString();

    printf("%s", str);

    free(str);
    return 0;
}
