#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> // Include this header to use strlen

int main(void)
{
    char str_name[15]; // 14 characters + null terminator

    printf("Please enter your first name to begin: ");
    // Use scanf instead of scanf_s for more compatibility unless you're working in an environment that requires scanf_s
    // Moreover, remove the unnecessary getchar and replace it with a check for the newline character.
    if(scanf("%14s", str_name) != 1){
        printf("Incorrect input.\n");
        return 1; // Exit if there is an input failure
    }
    
    // Clear the input buffer to remove any additional characters
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Discard rest of the characters and newline from the input buffer
    
    if (strlen(str_name) > 14) // This should check for greater than 14, not 15
    {
        printf("The entered name is too long, please restart the program and try again.\n");
        // Don't need a getchar here because we want it to exit anyway
        return 1; // Exit with a non-zero status to indicate an error
    }
    else
    {
        str_name[0] = toupper((unsigned char)str_name[0]); // Good practice to cast argument to unsigned char for standard library functions

        printf("Hi %s.\n", str_name);
        // Don't need a getchar here, the program will exit after displaying the message
    }
    
    return 0; // Successful execution
}
