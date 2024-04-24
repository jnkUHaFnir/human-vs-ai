#include <stdio.h>

int nextComb(int comb[], int k, int n) {
    int i = k - 1;

    while (i >= 0 && comb[i] == n - k + i) {
        i--;
    }

    if (i < 0) {
        return 0; // All combinations have been generated
    }

    comb[i]++;

    for (int j = i + 1; j < k; j++) {
        comb[j] = comb[i] + j - i;
    }

    return 1;
}

int main() {
    int k = 2; // Number of elements in each permutation
    int n = 4; // Range of elements [0, n-1]

    int comb[2] = {0, 1}; // Initial combination

    unsigned long long count = 0;

    do {
        // Do something with the current combination (e.g., print or process it)
        for (int i = 0; i < k - 1; i++) {
            printf("%d, ", comb[i]);
        }
        printf("%d\n", comb[k - 1]);

        count++;
    } while (nextComb(comb, k, n));

    printf("Total permutations: %llu\n", count);

    return 0;
}
