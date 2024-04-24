#include <stdio.h>

int nextPerm(int perm[], int k, int n) {
    int i, j;

    // Find the rightmost element that is smaller than its next element
    for (i = k - 2; i >= 0; i--) {
        if (perm[i] < perm[i + 1]) {
            break;
        }
    }

    // If no such element exists, we have reached the last permutation
    if (i == -1) {
        return 0;
    }

    // Find the smallest element on the right side of perm[i] that is greater than perm[i]
    for (j = k - 1; j > i; j--) {
        if (perm[j] > perm[i]) {
            break;
        }
    }

    // Swap the elements at indices i and j
    int temp = perm[i];
    perm[i] = perm[j];
    perm[j] = temp;

    // Reverse the elements from i+1 to k-1
    for (j = i + 1; j < (k + i + 1) / 2; j++) {
        temp = perm[j];
        perm[j] = perm[k + i - j];
        perm[k + i - j] = temp;
    }

    return 1;
}

int main() {
    int k = 2, n = 4; // Generate permutations of 2 elements out of 0, 1, 2, 3
    int perm[2] = {0, 1}; // Starting permutation

    unsigned long long count = 0;

    do {
        for (int a = 0; a < k - 1; a++) {
            printf("%d, ", perm[a]);
        }
        printf("%d\n", perm[k - 1]);

        count++;
    } while (nextPerm(perm, k, n));

    printf("\nTotal permutations: %llu\n", count);

    return 0;
}
