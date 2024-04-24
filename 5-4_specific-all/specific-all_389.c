#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Include ctype.h for toupper function

void uppercase(char source[]) // Changed return type to void since the function doesn't return anything
{
    int i;

    for(i=0; i<strlen(source); ++i) // Change i<=strlen(source) to i<strlen(source), because the index of a string starts from 0
    {
        if (source[i] >= 'a' && source[i] <= 'z')
        {
            source[i] = toupper(source[i]); // Use toupper function from ctype.h to convert to uppercase
        }
        // No need for 'else', just copying the character as is if it's not lowercase
    }
}

int main()
{
    char str[] = "cold"; // Define a string as an array to be modifiable

    uppercase(str); // Pass the array to the function

    printf("%s\n", str); // Output the modified string

    return 0;
}
