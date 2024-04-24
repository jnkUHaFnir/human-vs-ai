#include <stdio.h>

int main(void){
    float sales = 0;
    float salary = 0;
    int scanned = 0;  // Variable to check if valid input was scanned

    while (sales != -1)
    {
        printf("Enter sales in dollars (-1 to end): ");
        
        // Read the input and check if a float was successfully scanned
        scanned = scanf("%f", &sales);

        // If a float was not scanned successfully
        if (scanned != 1)
        {
            // Clear the input buffer
            while (getchar() != '\n');
            puts("Input error, please try again");
            continue; // Restart the loop to ask for input again
        }

        if (sales != -1)
        {
            salary = 200 + (0.09 * sales);
            printf("Salary is: $%.2f\n", salary);
        }
    }

    return 0;
}
