#include <stdio.h>
#include <string.h>

int main() {
    char email[100]; // Assuming 100 characters is enough for an email
    char temppass[64];
    char pass[] = "password";

    printf("Enter your email:\n");
    // No & needed for arrays with scanf. It's also better to limit input size to avoid overflow
    scanf("%64s", email); // %64s to prevent overflow, which might not work with some compilers/environments

    printf("Enter your password:\n");
    scanf("%63s", temppass); // Leave space for the NULL terminator

    if(strcmp(temppass, pass) == 0) {
        printf("This is the password\n");
    } else {
        printf("You Failed!\n");
    }

    return 0;
}
temppass[strcspn(temppass, "\n")] = 0; // Replace the newline with a null terminator
