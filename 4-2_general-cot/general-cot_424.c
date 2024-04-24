#include <stdio.h>
#include <stdlib.h> // Include this for malloc and free

char* getString()
{
    char buffer;
    int size = 0;
    int capacity = 1;

    char* inputString = (char*)malloc(capacity * sizeof(char));
    
    if(inputString == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    while(1)
    {
        buffer = getchar();
        if(buffer == '\n' || buffer == EOF) // Check for EOF as well
            break;
        if((capacity-1) <= size)
        {
            capacity *= 2;
            char* newString = (char*)realloc(inputString, capacity * sizeof(char));
            
            if(newString == NULL) {
                printf("Memory reallocation failed\n");
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
    printf("%s", str);
    free(str); // Free the memory allocated
    return 0;
}
