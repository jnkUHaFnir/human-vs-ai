#include <stdio.h>

int nextPerm(int perm[], int k, int n) {
    // Find the largest index i such that perm[i] < perm[i+1]
    int i = k - 1;
    while (i >= 0 && perm[i] == n - k + i) {
        i--;
    }

    // If no such index exists, all permutations have been generated
    if (i == -1) {
        return 0;
    }

    // Increment perm[i] and adjust subsequent elements
    perm[i]++;
    for (int j = i + 1; j < k; j++) {
        perm[j] = perm[j - 1] + 1;
    }

    return 1;
}

int main() {
    int k = 3, n = 10;
    int perm[3] = {0, 1, 2}; // Starting permutation
    unsigned long long count = 0;

    do {
        for (int a = 0; a < k - 1; a++)
            printf("%d, ", perm[a]);
        printf("%d\n", perm[k - 1]);
        count++;
    } while (nextPerm(perm, k, n));

    printf("\nTotal permutations: %llu\n", count);

    return 0;
}
