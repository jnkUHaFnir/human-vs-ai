if (strlen(str_name) >= 15)
{
    printf("The entered name is too long, please restart the program and try again.");
    getchar();
    exit(0);
}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> // Include string.h to use strlen()

int main(void)
{
    char str_name[15];

    printf("Please enter your first name to begin: ");
    scanf_s("%14s", str_name, sizeof(str_name)/sizeof(str_name[0]));
    getchar();
    
    if (strlen(str_name) >= 15)
    {
        printf("The entered name is too long, please restart the program and try again.");
        getchar();
        exit(0);
    }
    else
    {
        str_name[0] = toupper(str_name[0]);

        printf("Hi %s.\n", str_name);
        getchar();
    }
    
    return 0;
}
