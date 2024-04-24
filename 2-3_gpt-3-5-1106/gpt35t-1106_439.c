#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char email[100]; // Assuming email can be up to 100 characters
    char *temppass;
    char pass[] = "password";

    printf("Enter your email: \n");
    scanf("%s", email);

    temppass = (char*)malloc(64 * sizeof(char));

    printf("Enter your password: \n");
    scanf("%s" , temppass);

    if(strcmp(temppass, pass) == 0){
        printf("This is the correct password");
    }
    else{
        printf("You failed!");
    }

    free(temppass); // Free the allocated memory
    return 0;
}
