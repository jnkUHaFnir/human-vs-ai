#include <stdio.h>

int nextPermutation(int perm[], int k, int n) {
    int i = k - 1;
    while (i >= 0 && perm[i] == n - k + i) {
        i--;
    }

    if (i < 0) {
        return 0;  // No more permutations
    }

    perm[i]++;
    for (int j = i + 1; j < k; j++) {
        perm[j] = perm[i] + j - i;
    }

    return 1;
}

int main() {
    int n = 4;  // Range of elements
    int k = 2;  // Permutation length
    int perm[2] = {0};  // Initialize permutation

    do {
        for (int i = 0; i < k - 1; i++) {
            printf("%d, ", perm[i]);
        }
        printf("%d\n", perm[k - 1]);
    } while (nextPermutation(perm, k, n));

    return 0;
}
