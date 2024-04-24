#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float sales = 0;
    float salary = 0;
    char input[100];  // Buffer to hold the input

    while (1) {
        printf("Enter sales in dollars (-1 to end): ");
        fgets(input, sizeof(input), stdin);  // Read input as string

        // Try converting the input to a float
        if (sscanf(input, "%f", &sales) != 1) {
            printf("Input error, please try again\n");
            continue;  // goes to the next iteration of the loop
        }

        // Check if user wants to end the session
        if (sales == -1) {
            break;
        }

        // Check for a valid sales amount
        if (sales < 0) {
            printf("Sales cannot be negative. Please try again.\n");
            continue;  // goes to the next iteration of the loop
        }

        // Calculate and display salary
        salary = 200 + (0.09 * sales);
        printf("Salary is: $%.2f\n", salary);
    }

    return 0;
}
