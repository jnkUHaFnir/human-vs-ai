#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int isPrime(int num) {
    // Define the smallest prime number
    if (num <= 1) return 0; // 0 is not prime
    // 2 is the only even prime number
    if (num == 2) return 1; // 1 means prime
    // Exclude even numbers greater than 2
    if (num % 2 == 0) return 0;
    // Check for factors from 3 to sqrt(num)
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;

    // Prompt for the number of prime numbers
    do {
        printf("Input an integer: ");
        scanf("%d", &n);
    } while (n <= 0);

    int* v = (int*)malloc(n * sizeof(int));
    // Error check for malloc
    if (v == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    int count = 0;
    int num = 2; // Start checking from the first prime number, 2.
    
    while (count < n) {
        if (isPrime(num)) {
            v[count] = num;
            count++;
        }
        num++;
    }

    // Display the prime numbers
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(v);
    return 0;
}
