#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char str_name[16]; // Increased array size to accommodate 15 characters + null terminator

    printf("Please enter your first name to begin: ");
    scanf("%15s", str_name); // Read up to 15 characters to avoid buffer overflow

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
