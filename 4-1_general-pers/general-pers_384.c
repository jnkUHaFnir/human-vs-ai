#include <stdio.h>
#include <stdlib.h>

int main() {
    double a, b = -DBL_MAX; // Initialize b to the smallest possible value
    double n, i;
    
    printf("Enter the number of inputs: ");
    if (scanf("%lf", &n) != 1 || n <= 0) {
        printf("Invalid input for the limit. Please enter a positive number.\n");
        return 1;
    }

    for (i = 1; i <= n; i++) {
        printf("Enter number %d: ", (int)i);
        if (scanf("%lf", &a) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            return 1;
        }
        if (a > b) {
            b = a;
        }
    }

    printf("The largest number is: %.2f\n", b);

    return 0;
}
