#include <stdio.h>

int main(void) {
    float sales = 0;
    float salary = 0;
    int inputStatus;

    while (1) {
        printf("Enter sales in dollars (-1 to end): ");
        inputStatus = scanf("%f", &sales);

        if (inputStatus != 1) {
            // If the input is not a float value
            puts("Input error, please try again");
            while (fgetc(stdin) != '\n'); // Clear the input buffer
        }
        else if (sales == -1) {
            break;
        }
        else if (sales < 0) {
            // If the input is a negative value
            puts("Sales cannot be negative, please try again");
        }
        else {
            salary = 200 + (0.09 * sales);
            printf("Salary is: $%.2f\n", salary);
        }
    }

    return 0;
}
