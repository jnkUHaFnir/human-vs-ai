#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char input[50];
    char repeat;

    do
    {
        printf("Do you want to try again? (Y/N): ");
        fflush(stdin);                              
        fgets(input, sizeof(input), stdin);

        if (strlen(input) > 2)
        {
            repeat = 0;
        }
        else
        {
            if (input[strlen(input) - 1] == '\n')
            {
                input[strlen(input) - 1] = '\0';
            }
            repeat = toupper(input[0]);
        }

        if (repeat != 'Y' && repeat != 'N')         
            printf("Invalid answer. Please enter 'Y' or 'N'.\n\n");

    } while (repeat != 'N' && repeat != 'Y'); 

    return 0;
}
