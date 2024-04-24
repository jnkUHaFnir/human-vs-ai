#include <stdio.h>

int main() {
    double largest = 0.0, number, n;
    
    printf("Enter the number of inputs: ");
    if(scanf("%lf", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        printf("Enter number %d: ", i);
        if(scanf("%lf", &number) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
        
        if (number > largest) {
            largest = number;
        }
    }

    printf("The largest number is: %.2f\n", largest);

    return 0;
}
