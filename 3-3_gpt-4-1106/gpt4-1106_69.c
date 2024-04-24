#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024 

int main(void) {
    float sales = 0;
    float salary = 0;
    char inputBuffer[BUFFER_SIZE];

    while (1) {
        printf("Enter sales in dollars (-1 to end): ");
        fgets(inputBuffer, BUFFER_SIZE, stdin); // Read the whole line of input
        if (sscanf(inputBuffer, "%f", &sales) != 1) {
            // Non-numeric input or no input
            puts("Input error, please try again.");
            continue; // Skip further processing and prompt again
        }

        if (sales == -1) {
            // Exit condition
            break;
        } else if (sales >= 0) {
            // Calculate and display the salary
            salary = 200 + (0.09 * sales);
            printf("Salary is: $%.2f\n", salary);
        } else {
            puts("Input error, please try again.");
        }
    }

    return 0;
}
