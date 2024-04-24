#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char str_name[16]; // Need space for the null terminator

    printf("Please enter your first name to begin: ");
    fgets(str_name, sizeof(str_name), stdin);
    
    // Remove the newline character if it exists
    if (str_name[strlen(str_name) - 1] == '\n') {
        str_name[strlen(str_name) - 1] = '\0';
    }
    
    if (strlen(str_name) > 15)
    {
        printf("The entered name is too long, please restart the program and try again.\n");
    }
    else
    {
        str_name[0] = toupper(str_name[0]);

        printf("Hi %s.\n", str_name);
    }
    
    return 0;
}
