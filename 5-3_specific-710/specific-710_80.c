#include <stdio.h>

int main() {
    double salary;
    int inputCheck;
    
    printf("This program will compute your yearly and monthly withholding tax for you \n");
    
    do {
        printf("How much is your total monthly salary? ");
        inputCheck = scanf("%lf", &salary);

        if (inputCheck != 1) {
            printf("\nInvalid Input. Please enter a valid number.\n");
            while(getchar() != '\n'); // Clear input buffer
        } else if (salary < 0) {
            printf("\nSalary cannot be negative. Please enter a valid salary.\n");
        }

    } while (inputCheck != 1 || salary < 0);

    // Continue with the rest of your tax calculator logic here
    
    return 0;
}
