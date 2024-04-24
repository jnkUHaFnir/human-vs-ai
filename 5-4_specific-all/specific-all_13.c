#include <stdio.h>

unsigned long largestPrimeFactor(unsigned long n) {
    unsigned long i;
    unsigned long largestPrime = 1;

    // Divide by 2 until n is not divisible by 2
    while (n % 2 == 0) {
        largestPrime = 2;
        n = n / 2;
    }

    // Check for odd prime factors
    for (i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            largestPrime = i;
            n = n / i;
        }
    }

    // Handle case when n is a prime number greater than 2
    if (n > 2) {
        largestPrime = n;
    }

    return largestPrime;
}

int main() {
    unsigned long n;
    scanf("%lu", &n);

    unsigned long lpf = largestPrimeFactor(n);

    printf("%lu\n", lpf);

    return 0;
}
