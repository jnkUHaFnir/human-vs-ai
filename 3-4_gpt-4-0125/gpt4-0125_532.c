#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j;
    char str[1000];
    int found = 0; // This variable is used as a flag to indicate a repetition has been found

    scanf("%s", str); // Input the string

    for (i = 0; i < strlen(str) && !found; i++) // Loop until a repeated character is found or end of string
    {
        for (j = i + 1; j < strlen(str); j++)
        {
            if (str[i] == str[j]) // Compare
            {
                printf("%c", str[i]); // Print the first repeated character
                found = 1; // Set the flag as true to indicate that a repetition has been found
                break; // Exit the inner loop
            }
        }

        if (found) // Check if a repetition has been found
        {
            break; // Exit the outer loop if a repetition has been found
        }
    }

    if (!found) // Check if no repetition was found
    {
        printf("No repeated characters found.");
    }

    return 0;
}
