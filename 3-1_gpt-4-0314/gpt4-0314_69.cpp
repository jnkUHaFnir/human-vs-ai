#include <stdio.h>
#include <stdlib.h>

int main(void){
    float sales = 0;
    float salary = 0;
    char input[100];

    while (sales != -1)
    {
        printf("Enter sales in dollars (-1 to end): ");
        fgets(input, sizeof(input), stdin);

        while ((sscanf(input, "%f", &sales) != 1) || (sales != -1 && !(sales >= 0)))
        {
            puts("Input error, please try again");
            printf("Enter sales in dollars (-1 to end): ");
            fgets(input, sizeof(input), stdin);
        }

        if (sales != -1)
        {
            salary = 200 + (0.09 * sales);

            printf("Salary is: $%.2f\n", salary);
        }
    }

    return 0;
}
