#include <stdio.h>
#include <string.h>

void info() {
    // Dummy function to represent further actions.
    printf("\n Password Verified. Access Granted.\n");
}

void verification() {
    char pass[50];

    printf(" Enter Password: ");
    fgets(pass, 50, stdin);

    // Remove newline character if present
    pass[strcspn(pass, "\n")] = 0;

    // Use strcmp for string comparison and correct double quotes for string
    if (strcmp(pass, "aaanc6400") != 0) {
        printf("\n Invalid Password.. Please enter the correct password. \n\n");
        verification();
    } else {
        info();
    }
}

int main() {
    verification();
    return 0;
}
