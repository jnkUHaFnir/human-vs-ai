#include <stdio.h>
#include <string.h>

int main() {
    char email[100]; // Assuming the email can be up to 100 characters
    char temppass[64];
    char pass[] = "password";

    printf("Enter your email: \n");
    scanf("%s", email);

    printf("Enter your password: \n");
    scanf("%s", temppass);

    if (strcmp(temppass, pass) == 0) {
        printf("Logging in...\n");
    } else {
        printf("Incorrect password\n");
    }

    return 0;
}
