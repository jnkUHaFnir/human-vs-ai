#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double getSalaryInput() {
    char input[100]; // Adjust size as needed
    double salary;
    int success = 0;

    while (!success) {
        if (fgets(input, sizeof(input), stdin) != NULL) {
            // Attempt to convert the string to double
            char* endptr;
            salary = strtod(input, &endptr);

            // Check if conversion succeeded and the input was purely numeric
            if (endptr != input && *endptr == '\n') {
                success = 1; // Conversion successful
            } else {
                printf("Invalid input. Please enter a valid number: ");
            }

            // Additional check for negative values, if necessary
            if (salary < 0) {
                printf("Invalid Input. Please enter a positive number: ");
                success = 0;
            }
        } else {
            // Handle EOF or read error
            printf("An error occurred while reading the input.\n");
            // Clearing the input buffer to prevent infinite loop in case of error
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
    }

    return salary;
}

int main() {
    double salary;
    printf("This program will compute your yearly and monthly withholding tax for you.\n");
    printf("How much is your total monthly salary? ");
    salary = getSalaryInput();

    printf("Your salary: %lf\n", salary);

    // Further processing...

    return 0;
}
