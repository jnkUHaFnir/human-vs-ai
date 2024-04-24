#include <stdio.h>
#include <string.h>

int main()
{
    char password[] = "1sure";
    char input[15];

    do
    {
        printf("Password: ");

        if (scanf("%14s", input) != 1) {
            printf("No input detected.\n");
            // Clear the input buffer
            while (getchar() != '\n'); // flush the input buffer
            continue;
        }

        if(strcmp(password, input) == 0)
        {
            printf("Password accepted.\n");
            return 0;
        }
        else
        {
            printf("Invalid password.\n");
        }
    }
    while(1);

    return 0;
}
