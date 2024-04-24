inputString = newString;
free(newString);
// capacity *= 2; was here, but it's better moved below for clarity
newString = (char*)malloc(capacity*sizeof(char));
if (newString == NULL) {
    free(inputString); // Free original string if allocation fails
    return NULL; // Consider error handling here
}
int i;
for (i = 0; i < size; i++)
    newString[i] = inputString[i];
free(inputString); // Free the old space after the new space has been allocated
inputString = newString; // Now safe to reassign
// capacity *= 2; No need for this here again
#include <stdio.h>
#include <stdlib.h> // For malloc() and free()

char* getString()
{
    char buffer;
    int size = 0;
    int capacity = 1;
    char* inputString = (char*)malloc(capacity*sizeof(char));
    char* newString;

    if(inputString == NULL) return NULL; // Check if initial allocation fails

    while(1)
    {
        buffer = getchar();
        if(buffer == '\n')
            break;
        if((capacity-1) <= size)
        {
            capacity *= 2; // Double the capacity for exponential growth
            newString = (char*)malloc(capacity*sizeof(char));
            if (newString == NULL) {
                free(inputString); // Free original string if allocation fails
                return NULL; // Consider error handling here
            }
            for(int i = 0; i < size; i++) // Copy old content to the new space
                newString[i] = inputString[i];
            free(inputString); // This is the correct place to free the old string
            inputString = newString; // Now point to the new memory
        }
        inputString[size++] = buffer; // Post-increment size after assigning
    }
    inputString[size] = '\0'; // Null-terminate the string
    return inputString;
}
