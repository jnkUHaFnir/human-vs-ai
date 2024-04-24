#include <stdio.h>
#include <string.h>

int main()
{
    char email[100]; // Changed to an array
    char temppass[64];
    char pass[] = "password";

    printf("Enter your email: \n");
    scanf("%99s", email); // Limit size to prevent buffer overflow

    printf("Enter your password: \n");
    scanf("%63s", temppass); // Limit size to prevent buffer overflow

    // Remove \n character at the end of input for more accurate comparison
    // This will check the last character and replace it with a null terminator
    if (temppass[strlen(temppass) - 1] == '\n') {
        temppass[strlen(temppass) - 1] = '\0';
    }

    if(strcmp(temppass, pass) == 0){
        printf("This is the password\n");
    }
    else{
        printf("You Failed!\n");
    }

    return 0;
}
