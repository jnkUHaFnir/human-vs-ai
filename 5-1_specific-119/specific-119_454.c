#include <stdio.h>
#include <string.h>

void verification() {
    char pass[50];

    printf("Enter Password: ");
    fgets(pass, 50, stdin);

    if (strcmp(pass, "aaanc6400\n") != 0) {
        printf("\nInvalid Password. Please enter the correct password.\n\n");
        verification();
    } else {
        printf("\nCorrect Password!\n\n");
        // info(); // You may call info() here or perform other actions
    }
}

int main() {
    verification();
    return 0;
}
