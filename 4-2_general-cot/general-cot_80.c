#include <stdio.h>

int main() {
    double salary;
    int validInput = 0;

    printf("This program will compute your yearly and monthly withholding tax for you.\n");
    
    do {
        printf("How much is your total monthly salary? ");
        if(scanf("%lf", &salary) != 1) {
            printf("\nInvalid input. Please enter a valid number.\n");
            // clear input buffer
            while(getchar() != '\n');
        } else {
            validInput = 1;
        }
    } while(!validInput || salary < 0);

    // Continue with your program logic here

    return 0;
}
