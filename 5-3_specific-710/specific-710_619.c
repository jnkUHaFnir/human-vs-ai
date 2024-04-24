#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char str_name[16]; // Changed size to 16 to accommodate null terminator

    printf("Please enter your first name to begin: ");
    scanf("%15s", str_name); // Updated to use scanf instead of scanf_s

    if (strlen(str_name) > 15)
    {
        printf("The entered name is too long, please enter a shorter name.\n");
    }
    else
    {
        str_name[0] = toupper(str_name[0]);

        printf("Hi %s.\n", str_name);
    }
    
    return 0;
}
