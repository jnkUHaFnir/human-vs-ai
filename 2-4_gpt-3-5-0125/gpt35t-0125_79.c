#include <stdio.h>

int nextPerm(int perm[], int k, int n) {
    int i = k - 1;
    while (i >= 0 && perm[i] == n - k + i) {
        i--;
    }
    if (i < 0) {
        return 0;
    }
    perm[i]++;
    for (int j = i + 1; j < k; j++) {
        perm[j] = perm[j - 1] + 1;
    }
    return 1;
}

int main() {
    int k = 3;
    int n = 4; // Range of elements (0, 1, 2, 3)
    int perm[3] = {0, 1, 2}; // Starting permutation

    unsigned long long count = 0;

    do {
        for (int a = 0; a < k - 1; a++) {
            printf("%d, ", perm[a]);
        }
        printf("%d\n", perm[k - 1]);
        count++;
    } while (nextPerm(perm, k, n));

    printf("Total permutations: %llu\n", count);

    return 0;
}
