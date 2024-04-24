#include <stdio.h>
#include <string.h>
#include <ctype.h> // Include for isspace function

int main()
{
    char password[] = "1sure";
    char input[15];

    do
    {
        printf("Password: ");
        scanf("%14s", input); // Limit scanf to read up to 14 characters to prevent buffer overflow

        if(strcmp(password, input) == 0)
        {
            printf("Password accepted.\n");
            break;
        }
        else if(input[0] == '\0' || isspace(input[0])) // Check if input is empty or contains only whitespace
        {
            printf("No input detected. Please try again.\n");
        }
        else
        {
            printf("\nInvalid password.\n");
        }
    }
    while(1);

    return 0;
}
