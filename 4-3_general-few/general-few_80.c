#include <stdio.h>

int main() {
    double salary;
    int success;

    printf("This program will compute your yearly and monthly withholding tax for you\n");
    printf("How much is your total monthly salary? ");

    do {
        success = scanf("%lf", &salary);

        // Clear input buffer in case of incorrect input
        while (getchar() != '\n');

        if (success != 1 || salary < 0) {
            printf("\nInvalid Input\n");
            printf("How much is your total monthly salary? ");
        }
    } while (success != 1 || salary < 0);

    // Your code logic for tax calculation can go here

    return 0;
}
