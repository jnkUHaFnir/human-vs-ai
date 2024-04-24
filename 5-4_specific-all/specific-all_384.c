#include <stdio.h>

int main() {
    double a, b, n, i;
    
    printf("Enter the limit of input: ");
    scanf("%lf", &n);
    
    // Read the first number to initialize the maximum
    scanf("%lf", &b);
    
    for (i = 2; i <= n; i++) {
        scanf("%lf", &a);
        if (a > b) {
            b = a;
        }
    }
    
    printf("Largest number entered: %.2lf\n", b);
    
    return 0;
}
