#include <stdio.h>

int next_permutation(int *perm, int k, int n) {
    int i = k - 1;
    while (i >= 0 && perm[i] == n - 1) {
        perm[i] = 0;
        i--;
    }
    if (i < 0) {
        return 0; // All permutations generated
    }
    perm[i]++;
    return 1;
}

int main() {
    int n = 4; // Range
    int k = 2; // Permutation length
    int perm[k];
    for (int i = 0; i < k; i++) {
        perm[i] = i;
    }

    unsigned long long count = 0;
    do {
        for (int i = 0; i < k - 1; i++) {
            printf("%d, ", perm[i]);
        }
        printf("%d\n", perm[k - 1]);
        
        count++;
    } while (next_permutation(perm, k, n));

    printf("\nTotal count: %llu\n", count);

    return 0;
}
