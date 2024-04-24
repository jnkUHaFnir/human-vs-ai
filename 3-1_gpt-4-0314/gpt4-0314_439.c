char email[64];
scanf("%s", email);
scanf("%s", temppass);
fgets(temppass, sizeof(temppass), stdin);
temppass[strcspn(temppass, "\n")] = '\0';
#include <stdio.h>
#include <string.h>

int main()
{
    char email[64];
    char temppass[64];
    char pass[] = "password";

    printf("Enter your email: \n");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter your password: \n");
    fgets(temppass, sizeof(temppass), stdin);
    temppass[strcspn(temppass, "\n")] = '\0';

    if(strcmp(temppass, pass) == 0){
        printf("This is the password");
    }
    else{
        printf("You Failed!");
    }

    return 0;
}
