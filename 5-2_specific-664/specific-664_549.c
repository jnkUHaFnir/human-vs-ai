#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char input[256];
    char temp;
    int i = 0, j = 0;
    scanf("%s", input);
    j = strlen(input) - 1;

    while (i < j)
    {
        temp = input[j];
        input[j] = input[i];
        input[i] = temp;
        i++;
        j--;
    }
    printf("Reverse = %s", input);
    
    // Dynamically allocate memory for reversed string
    char *reversed = (char*)malloc(strlen(input) + 1); // +1 for the null terminator
    if(reversed == NULL) {
        printf("Memory allocation failed. Exiting...");
        return 1;
    }
    
    strcpy(reversed, input); // Copy reversed string to dynamically allocated memory
    
    printf("Reversed string using dynamically allocated memory = %s\n", reversed);
    
    free(reversed); // Free dynamically allocated memory
    
    return 0;
}
