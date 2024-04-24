#include <stdio.h>
#include <string.h>

int main()
{
    char email[100]; // define email as an array instead of a single char
    char temppass[64];
    const char pass[] = "password"; // const keyword makes the password read-only

    printf("Enter your email: \n");
    scanf("%99s", email); // limit the input size to avoid buffer overflow

    printf("Enter your password: \n");
    scanf("%63s", temppass); // limit the input size to avoid buffer overflow

    if(strcmp(temppass, pass) == 0){
        printf("This is the password");
    }
    else{
        printf("You Failed!");
    }

    return 0;
}
