#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char str_name[16]; // Increased the size to allow for a max length of 15 characters

    printf("Please enter your first name to begin: ");
    scanf("%15s", str_name); // Read at most 15 characters to prevent buffer overflow

    if (strlen(str_name) > 15)
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
