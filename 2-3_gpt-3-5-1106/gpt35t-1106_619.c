#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char str_name[15];

    printf("Please enter your first name to begin: ");
    scanf("%s", str_name);

    if (strlen(str_name) >= 15)
    {
        printf("The entered name is too long, please restart the program and try again.");
    }
    else
    {
        str_name[0] = toupper(str_name[0]);

        printf("Hi %s.\n", str_name);
    }

    return 0;
}
