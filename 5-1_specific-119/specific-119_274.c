#include <stdio.h>
#include <stdlib.h>

char* getString()
{
    char buffer;
    int size = 0;
    int capacity = 1;

    char* inputString = (char*)malloc(capacity*sizeof(char));
    
    if(inputString == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    
    while(1)
    {
        buffer = getchar();
        if(buffer == '\n')
            break;
        if((capacity-1) <= size)
        {
            capacity *= 2;
            char* newString = (char*)realloc(inputString, capacity*sizeof(char));
            
            if(newString == NULL) {
                // Handle memory reallocation failure
                free(inputString);
                return NULL;
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
    if(str != NULL) {
        printf("%s", str);
        free(str);
    } else {
        printf("An error occurred while getting the string.\n");
    }
    
    return 0;
}
