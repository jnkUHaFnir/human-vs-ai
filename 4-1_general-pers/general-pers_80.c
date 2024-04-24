#include <stdio.h>

int main() {
    double salary = 0.0;
    
    printf("This program will compute your yearly and monthly withholding tax for you \n");
    
    while (1) {
        printf("How much is your total monthly salary? ");
        
        if (scanf("%lf", &salary) != 1) {
            // If the input was not a valid double value
            printf("\n");
            printf("Invalid Input\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        } 
        
        if (salary < 0) {
            printf("\n");
            printf("Salary cannot be negative\n");
        } else {
            break;
        }
    }

    // Further processing with the validated salary value
    printf("Salary entered: %.2f\n", salary);

    return 0;
}
