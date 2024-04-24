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
        scanf("%s", input);

        if(strcmp(password, input) == 0)
        {
            printf("Password accepted.");
            putchar('\n');
            return 0;
        }
        else if(strlen(input) == 0 || (strlen(input) == 1 && isspace((unsigned char)input[0]))
        {
            printf("No input detected.\n");
            continue;
        }
        else
        {
            printf("\nInvalid password.\n");
        }
    }
    while(1);

    return 0;
}
