#include <stdio.h>

int main() {
    double salary;
    printf("This program will compute your yearly and monthly withholding tax for you.\n");

    while(1) {
        printf("How much is your total monthly salary? ");
        fflush(stdin);

        // Check if the input is a valid double value
        if (scanf("%lf", &salary) != 1) {
            printf("\nInvalid input. Please enter a valid number.\n");
            // Clear the input buffer to handle the invalid input
            while (getchar() != '\n');
        }
        else if (salary < 0) {
            printf("\nInvalid input. Salary should be a positive number.\n");
        }
        else {
            break;
        }
    }

    // Process the valid salary input
    printf("Salary input: %.2f\n", salary);

    return 0;
}
