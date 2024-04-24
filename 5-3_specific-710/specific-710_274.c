#include <stdio.h>
#include <stdlib.h>

char* getString()
{
    char buffer;
    int size = 0;
    int capacity = 1;

    char* inputString = (char*)malloc(capacity * sizeof(char));

    while(1)
    {
        buffer = getchar();
        if(buffer == '\n')
            break;
        if(capacity <= size + 1)
        {
            capacity *= 2;
            char* newString = (char*)malloc(capacity * sizeof(char));
            if(newString == NULL)
            {
                free(inputString);
                return NULL;
            }
            for(int i = 0; i < size; i++)
            {
                newString[i] = inputString[i];
            }
            free(inputString);
            inputString = newString;
        }
        inputString[size++] = buffer;
    }

    inputString[size] = '\0';
    return inputString;
}

int main()
{
    char* str = getString();
    if(str != NULL)
    {
        printf("Input String: %s\n", str);
        free(str);
    }
    else
    {
        printf("Error: Memory allocation failed!\n");
    }

    return 0;
}
