#include <stdio.h>

int main() {
    double a, b = 0, n;
    
    printf("Enter the number of inputs: ");
    if (scanf("%lf", &n) != 1 || n <= 0) {
        printf("Invalid input for the number of inputs.\n");
        return 1;
    }
    
    for (int i = 1; i <= n; i++) {
        printf("Enter number %d: ", i);
        if (scanf("%lf", &a) != 1) {
            printf("Invalid input for number %d.\n", i);
            return 1;
        }
        
        if (i == 1 || a > b) {
            b = a;
        }
    }

    printf("The largest number is: %.2lf\n", b);

    return 0;
}
