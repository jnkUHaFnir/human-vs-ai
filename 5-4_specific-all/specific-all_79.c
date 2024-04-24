#include <stdio.h>

int nextPermutation(int perm[], int k, int n) {
    int i = k - 1;
    
    // Find the largest index i such that perm[i] < perm[i+1]
    while (i >= 0 && perm[i] == n - k + i) {
        i--;
    }
    
    if (i == -1) {
        // No next permutation exists
        return 0;
    }
    
    perm[i]++;
    
    // Reset the elements after index i
    for (int j = i + 1; j < k; j++) {
        perm[j] = perm[j - 1] + 1;
    }
    
    return 1;
}

int main() {
    int k = 3; // Number of elements in each permutation
    int n = 10; // Range of numbers to choose from
    int perm[3] = {0, 1, 2}; // Initial permutation
    unsigned long long count = 0;

    do {
        for (int a = 0; a < k - 1; a++) {
            printf("%d, ", perm[a]);
        }
        printf("%d\n", perm[k - 1]);
        count++;
    } while (nextPermutation(perm, k, n));

    printf("\nTotal permutations: %llu\n", count);

    return 0;
}
