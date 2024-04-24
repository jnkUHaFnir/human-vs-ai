#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char input[100];
    float sales = 0;
    float salary = 0;

    while (1) {
        printf("Enter sales in dollars (-1 to end): ");
        fgets(input, sizeof(input), stdin);

        if (input[0] == '-' && input[1] == '1') {
            break; // Exit loop if input is -1
        }

        char *endptr;
        sales = strtof(input, &endptr);

        if (endptr == input || *endptr != '\n') {
            puts("Input error, please try again");
            continue; // Input was not a valid number
        }

        if (sales < 0) {
            puts("Input error: Sales cannot be negative, please try again");
            continue; // Sales cannot be negative
        }

        salary = 200 + (0.09 * sales);
        printf("Salary is: $%.2f\n", salary);
    }

    return 0;
}
