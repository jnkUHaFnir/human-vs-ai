#include <stdio.h>
#include <stdlib.h>

char* getString()
{
    char buffer;
    int size = 0;
    int capacity = 1;

    char* inputString = (char*)malloc(capacity);

    while(1)
    {
        buffer = getchar();
        if(buffer == '\n')
            break;
        if((capacity-1) <= size)
        {
            capacity *= 2;
            char* newString = (char*)malloc(capacity);
            int i;
            for(i = 0; i < size; i++)
                newString[i] = inputString[i];
            newString[size] = buffer;
            free(inputString);
            inputString = newString;
        }
        else
        {
            inputString[size] = buffer;
        }
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
    free(str); // Free the allocated memory
    return 0;
}
