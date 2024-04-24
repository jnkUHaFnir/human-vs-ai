#include <stdio.h>

unsigned long largestPrimeFactor(unsigned long n) {
    unsigned long lpf = 2;
    
    while (n > lpf) {
        if (n % lpf == 0) {
            n /= lpf;
        } else {
            lpf++;
        }
    }
    
    return lpf;
}

int main() {
    unsigned long n, lpf;
    printf("Enter a number: ");
    scanf("%lu", &n);
    
    lpf = largestPrimeFactor(n);

    printf("The largest prime factor of %lu is %lu\n", n, lpf);
    
    return 0;
}
