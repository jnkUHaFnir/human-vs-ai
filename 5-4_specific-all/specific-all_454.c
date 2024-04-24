#include <stdio.h>
#include <string.h>

void verification() {
    char pass[50];

    printf("Enter Password: ");
    fgets(pass, 50, stdin);

    // Remove the trailing newline character from fgets
    pass[strcspn(pass, "\n")] = '\0';

    if (strcmp(pass, "aaanc6400") != 0) {
        printf("\nInvalid Password. Please enter the correct password.\n\n");
        verification();
    } else {
        printf("\nPassword accepted!\n\n");
        info();
    }
}

void info() {
    // Function to perform actions after successful password verification
    printf("Access granted. Performing further operation...\n");
}

int main() {
    verification();
    return 0;
}
