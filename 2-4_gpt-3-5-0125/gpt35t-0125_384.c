#include <stdio.h>
int main () {
    double a, b, n, i;
    printf("limit of n input: ");
    scanf ("%lf", &n);
    
    scanf("%lf", &b); // Initialize b with the first input number

    for (i = 2; i <= n; i++) { // Start from i=2 since we've already read one number
        scanf("%lf", &a);
        if (a > b) b = a;
    }

    printf("%.2lf", b);

    return 0;
}
