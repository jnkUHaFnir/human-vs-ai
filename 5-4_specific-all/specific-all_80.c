#include <stdio.h>

int main() {
    double salary;
    int validInput = 0;

    printf("This program will compute your yearly and monthly withholding tax for you\n");
    
    do {
        printf("How much is your total monthly salary? ");
        fflush(stdin);
        
        if (scanf("%lf", &salary) != 1) {
            printf("\nInvalid Input. Please enter a valid number.\n\n");
            // Clear input buffer
            while (getchar() != '\n');
        } else {
            validInput = 1;
        }

    } while (!validInput);

    // Continue with your tax calculation using the valid salary value

    return 0;
}
