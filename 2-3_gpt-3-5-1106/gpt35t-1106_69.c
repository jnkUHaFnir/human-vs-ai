#include <stdio.h>

int main(void){
    float sales = 0;
    float salary = 0;

    while (1) // Infinite loop to process one salesperson's figures at a time
    {
        printf("Enter sales in dollars (-1 to end): ");
        
        // Check if the input is a number
        while (scanf("%f", &sales) != 1) 
        {
            // Clear the input buffer
            while (getchar() != '\n');
            // Prompt the user to enter a valid input
            puts("Input error, please try again");
            printf("Enter sales in dollars (-1 to end): ");
        }

        if (sales == -1) // Check for the end condition
        {
            break;
        }

        salary = 200 + (0.09 * sales);
        printf("Salary is: $%.2f\n", salary);
    }

    return 0;
}
