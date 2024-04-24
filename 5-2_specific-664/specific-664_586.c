#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int next_permutation(int perm[], int k, int n) {
    int i = k - 1;
    while (i > 0 && perm[i - 1] >= perm[i]) {
        i--;
    }

    if (i <= 0) {
        return 0; // Last permutation
    }

    int j = k - 1;
    while (perm[j] <= perm[i - 1]) {
        j--;
    }

    swap(&perm[i - 1], &perm[j]);

    j = k - 1;
    while (i < j) {
        swap(&perm[i], &perm[j]);
        i++;
        j--;
    }

    return 1; // Next permutation exists
}

int main() {
    int k = 3, n = 10;
    int perm[] = {0, 1, 2}; // Starting permutation

    unsigned long long count = 0;
    do {
        for (int a = 0; a < k - 1; a++) {
            printf("%d, ", perm[a]);
        }
        printf("%d\n", perm[k - 1]);
        count++;
    } while (next_permutation(perm, k, n));

    printf("\nTotal permutations: %llu\n", count);

    return 0;
}
