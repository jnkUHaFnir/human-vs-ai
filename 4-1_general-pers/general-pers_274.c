#include <stdio.h>
#include <stdlib.h> // Include necessary library for malloc and free

char* getString()
{
    char buffer;
    int size = 0;
    int capacity = 1;

    char* inputString = (char*)malloc(capacity * sizeof(char));
    
    if (inputString == NULL) {
        fprintf(stderr, "Memory allocation failed");
        exit(1);
    }

    while (1)
    {
        buffer = getchar();
        if (buffer == '\n')
            break;
        if ((capacity - 1) <= size)
        {
            capacity *= 2;
            char* newString = (char*)realloc(inputString, capacity * sizeof(char));

            if (newString == NULL) {
                fprintf(stderr, "Memory reallocation failed");
                free(inputString);
                exit(1);
            }

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
    free(str); // Free the allocated memory
    return 0;
}
