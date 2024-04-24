#include <stdio.h>
#include <string.h>

void verification() {
    char pass[50];
    char storedPassword[] = "aaanc6400";

    printf("Enter Password: ");
    fgets(pass, sizeof(pass), stdin);

    // Remove the newline character from the entered password
    pass[strcspn(pass, "\n")] = 0;

    if (strcmp(pass, storedPassword) != 0) {
        printf("\nInvalid Password. Please enter the correct password.\n\n");
    } else {
        printf("\nPassword is correct.\n\n");
        info();
    }
}

int main() {
    verification();
    return 0;
}
