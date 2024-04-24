#include <stdio.h>
#include <stdlib.h>

char* getString()
{
    char buffer;
    int size = 0;
    int capacity = 1;

    char* inputString = malloc(capacity*sizeof(char));
    char* newString;

    while(1)
    {
        buffer = getchar();
        if(buffer == '\n')
            break;
        if((capacity-1) <= size)
        {
            capacity *= 2;
            newString = realloc(inputString, capacity * sizeof(char)); // Reallocate to a bigger size and return new address
            if(newString == NULL)
            {
                printf("Memory allocation failed!\n"); // Just for safe case
                free(inputString); // Free the original block
                exit(1);
            }
            else
                inputString = newString; // Assign the new address to inputString
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
    free(str); // Free the dynamically allocated string
}
