#include <stdio.h>
#include <stdlib.h> // Important to include for malloc and free

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
            newString = (char*)realloc(inputString, capacity*sizeof(char)); // Use realloc instead
            if (newString != NULL) // Check if realloc was successful
            {
                inputString = newString;
            }
            else
            {
                // Handle realloc failure: free original block and return or handle differently
                free(inputString);
                return NULL; // Example handling by returning NULL
            }
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
    if (str != NULL) // Check if getString returned NULL
    {
        printf("%s", str);
    }
    else
    {
        printf("An error occurred while reading the input.");
    }

    free(str); // Remember to free the allocated memory
    return 0;
}
