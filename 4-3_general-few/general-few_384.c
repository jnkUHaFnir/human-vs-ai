#include <stdio.h>

int main() {
    double a, b, n, i;
    
    printf("Limit of n input: ");
    scanf("%lf", &n);

    // Initialize b with the first input number
    scanf("%lf", &b);

    for (i = 2; i <= n; i++) { // Start from 2 since we already read the first number
        scanf("%lf", &a);
        if (a > b) {
            b = a;
        }
    }

    printf("Largest number: %.2lf\n", b);

    return 0;
}
