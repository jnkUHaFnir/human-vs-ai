#include <stdio.h>

int main(void){
    float sales = 0;
    float salary = 0;
    int scanfResult = 0;

    while (sales != -1)
    {
        printf("Enter sales in dollars (-1 to end): ");
        scanfResult = scanf("%f", &sales);

        if (scanfResult != 1) {
            // Clear the input buffer
            while(getchar() != '\n');
            puts("Input error, please try again");
            continue; // Restart the loop
        }

        if (sales != -1)
        {
            salary = 200 + (0.09 * sales);
            printf("Salary is: $%.2f\n", salary);
        }
    }

    return 0;
}
