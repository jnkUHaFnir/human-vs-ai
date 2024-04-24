#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isNumeric(const char* str) {
    while (*str) {
        if (*str < '0' || *str > '9') {
            return false;
        }
        str++;
    }
    return true;
}

int main(void){
    char input[100];
    float sales = 0;
    float salary = 0;

    while (true)
    {
        printf("Enter sales in dollars (-1 to end): ");
        fgets(input, sizeof(input), stdin);
        
        if (strcmp(input, "-1\n") == 0) {
            break;
        }

        if (!isNumeric(input)) {
            puts("Input error, please try again");
            continue;
        }

        sales = atof(input);

        if (sales < 0) {
            puts("Input error, please try again");
            continue;
        }

        salary = 200 + (0.09 * sales);
        printf("Salary is: $%.2f\n", salary);
    }

    return 0;
}
