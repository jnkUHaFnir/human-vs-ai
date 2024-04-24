#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[] = "1sure";
    char input[15];

    do
    {
        printf("Password: ");
        scanf("%14s", input); // Limit input to prevent buffer overflow

        if(strlen(input) == 0)
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
            printf("Invalid password.\n");
            continue;
        }
    }
    while(1);

    return 0;
}
