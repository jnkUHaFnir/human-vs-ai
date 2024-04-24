#include <stdio.h>
#include <string.h>

void info() {
    printf("Access granted! Welcome to the system.\n");
}

void verification() {
    char pass[50];

    printf("Enter Password : ");
    fgets(pass, 50, stdin);

    if (strcmp(pass, "aaanc6400\n") != 0) // Corrected comparison
    {
        printf("\nInvalid Password. Please enter the correct password.\n");
        verification();
    } else {
        info();
    }
}

int main() {
    verification();

    return 0;
}
