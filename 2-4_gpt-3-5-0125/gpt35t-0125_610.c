#include <stdio.h>
#include <string.h>

int main()
{
    char password[] = "1sure";
    char input[15];

    do
    {
        printf("Password: ");
        scanf("%s", input);

        if(strlen(input) == 0) // Check if no input was entered
        {
            printf("No input detected.\n");
            continue;
        }

        if(strcmp(password, input) == 0)
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
    while(1);

    return 0;
}
