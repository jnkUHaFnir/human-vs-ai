#include <stdio.h>
#include <string.h>

int main()
{
    char password[] = "1sure";
    char input[15];

    do
    {
        printf("Password: ");
        fgets(input, sizeof(input), stdin);

        // Remove the newline character at the end
        input[strcspn(input, "\n")] = 0;

        if (strcmp(password, input) == 0)
        {
            printf("Password accepted.\n");
            return 0;
        }
        else if (input[0] == '\0')
        {
            printf("No input detected, please try again.\n");
        }
        else
        {
            printf("\nInvalid password.\n");
        }
    } while (1);

    return 0;
}
