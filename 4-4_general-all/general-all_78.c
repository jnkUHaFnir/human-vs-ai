#include <stdio.h>
#include <stdbool.h>

// Function to generate the next permutation based on the current permutation
bool nextPerm(int perm[], int k, int n) {
    int i = k - 1;
    
    while (i >= 0 && perm[i] == n - k + i) {
        i--;
    }
    
    if (i == -1) {
        return false; // No more permutations
    }

    perm[i]++;

    for (int j = i + 1; j < k; j++) {
        perm[j] = perm[i] + j - i;
    }

    return true;
}

int main() {
    int k = 2; // Length of permutations
    int n = 4; // Range of elements
    int perm[2] = {0, 1}; // Starting permutation

    unsigned long long count = 0;

    do {
        for (int i = 0; i < k - 1; i++) {
            printf("%d, ", perm[i]);
        }
        printf("%d\n", perm[k - 1]);

        count++;
    } while (nextPerm(perm, k, n));

    printf("\nTotal permutations: %llu", count);

    return 0;
}
