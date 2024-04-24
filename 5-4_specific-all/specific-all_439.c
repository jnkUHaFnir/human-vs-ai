#include <stdio.h>
#include <string.h>

int main()
{
    char email[64]; // define as an array of characters
    char temppass[64];
    char pass[] = "password";

    printf("Enter your email: \n");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0; // remove the trailing newline character

    printf("Enter your password: \n");
    fgets(temppass, sizeof(temppass), stdin);
    temppass[strcspn(temppass, "\n")] = 0; // remove the trailing newline character

    if(strcmp(temppass, pass) == 0){
        printf("This is the password\n");
    }
    else{
        printf("You Failed!\n");
    }

    return 0;
}
