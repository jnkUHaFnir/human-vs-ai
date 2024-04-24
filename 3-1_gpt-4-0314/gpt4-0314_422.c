#include <stdio.h>
#include <stdlib.h>

char* getString()
{
    char buffer;
    int size = 0;
    int capacity = 1;

    char* inputString = (char*)malloc(capacity * sizeof(char));
    char* newString;

    while (1)
    {
        buffer = getchar();
        if (buffer == '\n')
            break;
        if ((capacity - 1) <= size)
        {
            capacity *= 2;
            newString = (char*)malloc(capacity * sizeof(char));
            int i;
            for (i = 0; i < size; i++)
                newString[i] = inputString[i];

            free(inputString); // Free the old inputString memory
            inputString = newString; // Assign the newString to inputString
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
    free(str); // Don't forget to free the memory when you're done with the string
    return 0;
}
