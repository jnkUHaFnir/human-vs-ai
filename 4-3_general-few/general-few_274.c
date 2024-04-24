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
        if((capacity - 1) <= size)
        {
            capacity *= 2;
            char* newString = (char*)malloc(capacity * sizeof(char));
            int i;
            for(i = 0; i < size; i++)
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
    printf("%s\n", str);

    free(str); // Freeing the inputString after usage
    return 0;
}
