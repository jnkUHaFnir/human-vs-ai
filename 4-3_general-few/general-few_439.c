#include <stdio.h>
#include <string.h>

int main()
{
    char email[100];
    char temppass[64];
    char pass[] = "password";
    
    printf("Enter your email: \n");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = 0; // Removes the newline character
    
    printf("Enter your password: \n");
    fgets(temppass, sizeof(temppass), stdin);
    temppass[strcspn(temppass, "\n")] = 0; // Removes the newline character

    if(strcmp(temppass, pass) == 0){
        printf("This is the password\n");
    }
    else{
        printf("You Failed!\n");
    }

    return 0;
}

