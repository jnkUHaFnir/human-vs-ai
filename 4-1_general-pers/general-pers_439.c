#include <stdio.h>
#include <string.h>

int main() {
    char email[64]; // Changed to array
    char temppass[64];
    char pass[] = "password";

    printf("Enter your email: \n");
    scanf("%63s", email); // Limit input size to prevent buffer overflow

    printf("Enter your password: \n");
    scanf("%63s" , temppass); // Limit input size to prevent buffer overflow

    // Clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    if(strcmp(temppass, pass) == 0) {
        printf("This is the password\n");
    } else {
        printf("You Failed!\n");
    }

    return 0;
}
