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

    while(1)
    {
        buffer = getchar();
        if(buffer == '\n')
            break;

        if ((size + 1) >= capacity)
        {
            capacity *= 2;
            char* newString = (char*)malloc(capacity * sizeof(char));

            if (newString == NULL) {
                printf("Memory allocation failed.\n");
                free(inputString);
                return NULL;
            }
            
            for (int i = 0; i < size; i++)
                newString[i] = inputString[i];

            free(inputString);
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
        free(str);
    }

    return 0;
}
