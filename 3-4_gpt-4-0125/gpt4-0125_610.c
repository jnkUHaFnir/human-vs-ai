#include <stdio.h>
#include <string.h>
#include <ctype.h> // Include ctype.h for isspace function.

int main()
{
    char password[] = "1sure";
    char input[15];
    char buffer[100]; // Buffer for fgets

    do
    {
        printf("Password: ");
        // Use fgets to get the line of input including spaces
        if(fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            // Try to scan a string from buffer to input
            if(sscanf(buffer, "%14s", input) == 1)
            {
                if(strcmp(password,input) == 0)
                {
                    printf("Password accepted.\n");
                    return 0;
                }
                else
                {
                    printf("\nInvalid password.\n");
                    continue;
                }
            }
            else
            {
                // Input was empty or whitespace only
                printf("No input detected.\n");
                continue;
            }
        }
    }
    while(1); // Infinite loop, control exits via return statement
}
