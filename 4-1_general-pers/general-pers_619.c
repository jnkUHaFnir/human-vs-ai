#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_NAME_LENGTH 15

int main(void)
{
    char str_name[MAX_NAME_LENGTH + 1]; // Added +1 for the null terminator

    printf("Please enter your first name to begin: ");
    fgets(str_name, sizeof(str_name), stdin);
    
    // Remove the newline character at the end of the input
    str_name[strcspn(str_name, "\n")] = '\0';

    if (strlen(str_name) > MAX_NAME_LENGTH)
    {
        printf("The entered name is too long, please restart the program and try again.\n");
        return 1; // Returning a non-zero value to indicate an error
    }
    else
    {
        str_name[0] = toupper((unsigned char)str_name[0]); // Added type casting to handle negative values

        printf("Hi %s.\n", str_name);
    }
    
    return 0;
}
