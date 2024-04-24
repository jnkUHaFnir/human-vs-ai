#include <stdio.h>
#include <string.h>

int main()
{
    char email[256]; // Email declared as an array of characters
    char temppass[64];
    char pass[] = "password";

    printf("Enter your email:\n");
    scanf("%255s", email); // Limit input size and remove the '&' operator for arrays

    printf("Enter your password:\n");
    scanf("%63s", temppass); // Limit input size and remove the '&' operator for arrays

    if(strcmp(temppass, pass) == 0){
        printf("This is the password.\n");
    }
    else{
        printf("You Failed!\n");
    }

    return 0;
}
// ... rest of the code

printf("Enter your email:\n");
fgets(email, sizeof(email), stdin);
email[strcspn(email, "\n")] = 0; // Remove newline character if present

printf("Enter your password:\n");
fgets(temppass, sizeof(temppass), stdin);
temppass[strcspn(temppass, "\n")] = 0; // Remove newline character if present

// ... rest of the strcmp() and output code
