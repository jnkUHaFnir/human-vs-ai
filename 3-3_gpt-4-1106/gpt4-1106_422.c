#include <stdio.h>
#include <stdlib.h>

char* getString()
{
    char buffer;
    int size = 0;
    int capacity = 1;

    char* inputString = (char*)malloc(capacity * sizeof(char));
    if (inputString == NULL) {
        return NULL; // Handle malloc failure
    }
    
    while (1)
    {
        buffer = getchar();
        if (buffer == '\n' || buffer == EOF) {
            break;
        }
        if (size >= capacity - 1)
        {
            capacity *= 2;
            // Use realloc to increase the size of the already allocated memory block
            char* newString = (char*)realloc(inputString, capacity * sizeof(char));
            if (newString == NULL) {
                free(inputString); // Free the previously allocated memory if realloc fails
                return NULL; // Handle realloc failure
            }
            inputString = newString;
        }
        inputString[size++] = buffer;
    }
    inputString[size] = '\0'; // Null-terminate the string
    return inputString;
}

int main()
{
    char* str;
    str = getString();
    if (str != NULL) {
        printf("%s", str);
        free(str); // Don't forget to free the memory after you are done using it
    } else {
        printf("Failed to read input.\n");
    }
    return 0;
}
