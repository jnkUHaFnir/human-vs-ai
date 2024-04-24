#include <stdio.h>

int main(void){
    float sales = 0;
    float salary = 0;
    int c;

    while (1)
    {
        printf("Enter sales in dollars (-1 to end): ");
        if (scanf("%f", &sales) != 1) {
            while ((c = getchar()) != '\n' && c != EOF); // Clear input buffer
            puts("Input error, please try again");
            continue;
        }

        if (sales == -1) {
            break;
        }

        if (sales >= 0)
        {
            salary = 200 + (0.09 * sales);

            printf("Salary is: $%.2f\n", salary);
        } else {
            puts("Input error, please try again");
        }
    }

    return 0;
}
