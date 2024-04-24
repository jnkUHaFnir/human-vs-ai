#include <stdio.h>

int main() {
    double a, b = 0, n, i;
    
    printf("Enter the limit of input (n): ");
    if (scanf("%lf", &n) != 1 || n <= 0 || n != (int)n) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    for (i = 1; i <= n; i++) {
        printf("Enter number %d: ", (int)i);
        if (scanf("%lf", &a) != 1) {
            printf("Invalid input. Please enter a number.\n");
            return 1;
        }
        if (a > b) {
            b = a;
        }
    }

    printf("The largest number is %.2lf\n", b);

    return 0;
}
