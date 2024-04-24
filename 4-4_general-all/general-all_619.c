#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_NAME_LENGTH 15

int main(void)
{
    char str_name[MAX_NAME_LENGTH + 1]; // Added 1 for null terminator

    printf("Please enter your first name to begin: ");
    scanf("%15s", str_name); // Read up to 15 characters to avoid buffer overflow
    
    // Clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    if (strlen(str_name) >= MAX_NAME_LENGTH)
    {
        printf("The entered name is too long. Please restart the program and try again.\n");
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
