#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> // Include for strlen()

int main(void)
{
    char str_name[16]; // Increase size to 16 to allow for 15 characters + null terminator
    printf("Please enter your first name to begin: ");
    // Read up to 15 characters to leave room for the null terminator
    if (scanf("%15s", str_name) != 1) { 
        printf("Input error.\n");
        exit(1);
    }
    getchar(); // Consume the newline character to clear the input buffer
    
    if (strlen(str_name) > 15) {
        printf("The entered name is too long, please restart the program and try again.\n");
        // No need to call getchar() before exit since we want to exit immediately
        exit(0);
    } else {
        // Upper case the first letter of the entered name
        str_name[0] = toupper(str_name[0]);
        printf("Hi %s.\n", str_name);
        getchar(); // Wait for user input before closing, optional based on program needs
    }
    return 0;
}
