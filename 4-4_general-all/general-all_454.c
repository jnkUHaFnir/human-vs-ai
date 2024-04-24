#include <stdio.h>
#include <string.h>

void info() {
    printf("\n Password correct. Access granted.\n");
}

void verification() {
    char pass[50];

    printf(" Enter Password : ");
    fgets(pass, 50, stdin);

    // Compare the input password with the correct password using strcmp
    if (strcmp(pass, "aaanc6400\n") != 0) {
        printf("\n Invalid Password.. Please enter the correct password. \n\n");
        verification();
    }
    info();
}

int main() {
    verification();
    return 0;
}
