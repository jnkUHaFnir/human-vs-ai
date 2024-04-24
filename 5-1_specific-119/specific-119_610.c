#include <stdio.h>
#include <string.h>
#include <ctype.h> // Include ctype.h for isgraph

int main()
{
    char password[] = "1sure";
    char input[15];

    do
    {
        printf("Password: ");
        fgets(input, sizeof(input), stdin); // Use fgets to read input

        // Remove the newline character at the end if present
        input[strcspn(input, "\n")] = '\0';

        if(strcmp(password, input) == 0)
        {
            printf("Password accepted.\n");
            return 0;
        }
        else if(strlen(input) == 0) // Check if input is empty
        {
            printf("No input detected.\n");
            continue;
        }
        else
        {
            printf("\nInvalid password.\n");
            continue;
        }
    }
    while(1);

    return 0;
}
