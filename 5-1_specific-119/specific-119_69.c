#include <stdio.h>

int main(void) {
    float sales = 0;
    float salary = 0;
    int result;

    while (1) {
        printf("Enter sales in dollars (-1 to end): ");
        result = scanf("%f", &sales);

        if (result != 1) {  // Check if the input was successfully read as a float
            printf("Invalid input. Please enter a valid number.\n");
            while (fgetc(stdin) != '\n');  // Clearing invalid input from stdin
            continue;
        }

        if (sales == -1) {
            break;
        } else if (sales < 0) {
            printf("Input error. Sales amount cannot be negative.\n");
            continue;
        }

        salary = 200 + (0.09 * sales);
        printf("Salary is: $%.2f\n", salary);
    }

    return 0;
}
