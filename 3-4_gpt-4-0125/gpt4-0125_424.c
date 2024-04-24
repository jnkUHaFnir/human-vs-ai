#include <stdio.h>
#include <stdlib.h> // Include this for malloc and free

char* getString()
{
    char buffer;
    int size = 0;
    int capacity = 1;
    
    char* inputString = (char*)malloc(capacity * sizeof(char));
    char* newString;

    if(inputString == NULL) // Check if malloc was successful
        return NULL;

    while (1)
    {
        buffer = getchar();
        if (buffer == '\n' || buffer == EOF) // Handle EOF as well
            break;

        if (size + 1 >= capacity)
        {
            capacity *= 2;
            newString = (char*)realloc(inputString, capacity * sizeof(char)); // Use realloc for simplicity
            if (newString == NULL) // Check if realloc was successful
            {
                free(inputString); // Clean up in case of failure
                return NULL;
            }
            inputString = newString;
        }
        inputString[size++] = buffer; // Update size after assignment
    }
    inputString[size] = '\0';
    return inputString;
}

int main()
{
    char* str = getString();
    if (str == NULL) {
        printf("Error allocating memory!\n");
    } else {
        printf("%s", str);
        free(str); // Don't forget to free the memory to prevent a memory leak
    }
    return 0;
}
