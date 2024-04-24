#include <stdio.h>
#include <string.h>

int main()
{
    char email[50]; // Changed to an array to store a string
    char temppass[64];
    char pass[] = "password";

    printf("Enter your email: \n");
    fgets(email, 50, stdin); // Using fgets to read input

    printf("Enter your password: \n");
    fgets(temppass, 64, stdin); // Using fgets to read input

    // Remove newline characters from the strings
    email[strcspn(email, "\n")] = 0;
    temppass[strcspn(temppass, "\n")] = 0;

    if (strcmp(temppass, pass) == 0) {

        printf("This is the correct password\n");

    } else {

        printf("You Failed!\n");

    }

    return 0;
}
