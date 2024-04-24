if((capacity-1) <= size)
{
    capacity *= 2;
    newString = (char*)malloc(capacity*sizeof(char));
    int i;
    for(i = 0; i < size; i++)
        newString[i] = inputString[i];
    inputString = newString;
    free(newString);
}
#include <stdio.h>
#include <stdlib.h>

char* getString()
{
    int size = 0;
    int capacity = 1;

    char* inputString = (char*)malloc(capacity * sizeof(char));
    char* newString;
    char buffer;

    if (inputString == NULL) {
        return NULL; // Check if memory allocation failed and return NULL to handle the error gracefully.
    }

    while (1)
    {
        buffer = getchar();
        if (buffer == '\n' || buffer == EOF) {
            break;
        }
        if (size + 1 >= capacity)
        {
            capacity *= 2; // Double the capacity
            newString = (char*)realloc(inputString, capacity * sizeof(char));
            if (newString == NULL) {
                free(inputString); // Free the old memory if realloc fails
                return NULL;
            }
            inputString = newString;
        }
        inputString[size++] = buffer;
    }
    inputString[size] = '\0';
    return inputString;
}

int main()
{
    char* str;
    str = getString();
    if (str != NULL) {
        printf("%s\n", str);
        free(str); // Don't forget to free the memory when done
    } else {
        printf("Memory allocation failed.\n");
    }
    return 0;
}
