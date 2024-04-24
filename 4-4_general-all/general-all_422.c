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
        if(size >= capacity - 1)
        {
            capacity *= 2;
            char* newString = (char*)malloc(capacity * sizeof(char));
            for(int i = 0; i < size; i++)
                newString[i] = inputString[i];
            free(inputString); // Free the old inputString after copying to newString
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
    free(str); // Free the allocated memory after its use
    return 0;
}
