#include <stdio.h>
#include <limits.h> // for INT_MIN if working with integers

int main() {
    double max = -INFINITY; // set initial max to smallest possible value

    int n;
    printf("Limit of n input: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        double num;
        printf("Enter number %d: ", i);
        scanf("%lf", &num);

        if (num > max) {
            max = num;
        }
    }

    printf("The largest number is: %.2lf\n", max);

    return 0;
}
