#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char str_name[16]; // Increase size to accommodate null terminator

    printf("Please enter your first name to begin: ");
    fgets(str_name, sizeof(str_name), stdin);

    // Calculate the length of input string
    size_t len = strlen(str_name);
    if (len > 0 && str_name[len - 1] == '\n') {
        str_name[len - 1] = '\0'; // Remove newline character if present
        len--; // Update length after removing newline character
    }

    if (len > 15)
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
