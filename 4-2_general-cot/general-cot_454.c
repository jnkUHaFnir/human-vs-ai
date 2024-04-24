#include <stdio.h>
#include <string.h>

void info() {
    printf("\n Access granted. You are now in the system. \n\n");
    // Add your info display logic here
}

void verification() {
    char pass[50];

    printf(" Enter Password : ");
    fgets(pass, 50, stdin);

    // Remove newline character from password
    pass[strcspn(pass, "\n")] = 0;

    if (strcmp(pass, "aaanc6400") != 0) {
        printf("\n Invalid Password. Please enter the correct password. \n\n");
        verification(); // You can limit the number of retries here
    } else {
        info();
    }
}

int main() {
    verification();
    return 0;
}
