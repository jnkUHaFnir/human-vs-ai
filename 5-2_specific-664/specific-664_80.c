#include <stdio.h>

int main() {
    double salary;
    int numArgsRead;

    printf("This program will compute your yearly and monthly withholding tax for you\n");
    do {
        printf("How much is your total monthly salary? ");
        fflush(stdout); // Flush the output buffer to ensure prompt output

        // Read the input and store the number of arguments successfully assigned
        numArgsRead = scanf("%lf", &salary);

        // Clear the input buffer in case of invalid input
        while (getchar() != '\n');

        if(numArgsRead != 1) {
            printf("\nInvalid input. Please enter a valid number.\n");
        }
    } while(numArgsRead != 1 || salary < 0);

    // Proceed with the rest of your program logic here using the validated salary value

    return 0;
}
