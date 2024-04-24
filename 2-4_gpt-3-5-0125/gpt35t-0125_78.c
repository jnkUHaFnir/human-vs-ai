#include <stdio.h>

int next_permutation(int perm[], int k, int n) {
    int i = k - 1;
    while (i >= 0 && perm[i] == n - k + i) {
        i--;
    }
    if (i < 0) {
        return 0; // No more permutations
    }

    perm[i]++;
    for (int j = i + 1; j < k; j++) {
        perm[j] = perm[j - 1] + 1;
    }

    return 1;
}

int main() {
    int k = 2, n = 4;
    int perm[2] = {0, 1};
    unsigned long long count = 0;

    do {
        for (int i = 0; i < k - 1; i++) {
            printf("%d, ", perm[i]);
        }
        printf("%d\n", perm[k - 1]);

        count++;
    } while (next_permutation(perm, k, n));

    printf("\n%llu", count);
    
    return 0;
}
