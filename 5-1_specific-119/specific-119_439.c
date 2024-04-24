#include <stdio.h>
#include <string.h>

int main()
{
    char email[100]; // Changed from char to char array
    char temppass[64];
    char pass[] = "password";

    printf("Enter your email: \n");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0'; // Removing new line character

    printf("Enter your password: \n");
    fgets(temppass, sizeof(temppass), stdin);
    temppass[strcspn(temppass, "\n")] = '\0'; // Removing new line character

    if(strcmp(temppass, pass) == 0) {
        printf("This is the correct password.\n");
    }
    else {
        printf("You Failed!\n");
    }

    return 0;
}
