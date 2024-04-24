#include <stdio.h>
#include <string.h>

int main()
{
    char email[64];
    char temppass[64];
    char pass[] = "password";

    printf("Enter your email: \n");
    scanf("%s", email);

    printf("Enter your password: \n");
    scanf("%s" , temppass);

    if(strcmp(temppass, pass) == 0){
        printf("This is the password");
    }
    else{
        printf("You Failed!");
    }

    return 0;

}
