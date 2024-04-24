#include <stdio.h>

int main() {
    double a, b, n;
    int i;

    printf("limit of n input: ");
    scanf("%lf", &n);

    if (n <= 0) {
        printf("Please enter a positive number of inputs.\n");
        return 1;
    }

    // Read the first number before the loop to initialize `b` with it.
    printf("Enter number 1: ");
    scanf("%lf", &b);

    for (i = 2; i <= n; i++) { // Start from 2 since we already have the first number.
        printf("Enter number %d: ", i);
        scanf("%lf", &a);
        if (a > b) b = a;
    }

    printf("The largest number is %.2lf\n", b);

    return 0;
}
