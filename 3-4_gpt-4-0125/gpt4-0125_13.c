#include <stdio.h>

// Function to find the largest prime factor
unsigned long largestPrimeFactor(unsigned long n) {
    unsigned long maxPrime = -1;

    // Divide out all factors of 2 to start
    while (n % 2 == 0) {
        maxPrime = 2;
        n /= 2;
    }

    // n must be odd at this point, so start checking from 3
    for (unsigned long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            maxPrime = i;
            n = n / i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2) {
        maxPrime = n;
    }

    return maxPrime;
}

int main() {
    unsigned long n;
    scanf("%lu", &n); // Corrected format specifier
    unsigned long lpf = largestPrimeFactor(n);
    printf("%lu", lpf); // Corrected format specifier
    return 0;
}
