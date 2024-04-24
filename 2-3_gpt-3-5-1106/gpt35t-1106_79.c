#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int next_permutation(int perm[], int k, int n) {
    // Find the largest index i such that perm[i] < perm[i+1]
    int i = k - 2;
    while (i >= 0 && perm[i] >= perm[i + 1]) {
        i--;
    }
    if (i == -1) {  // If no such index exists, permutation is the last permutation
        return 0;
    }

    // Find the largest index j such that perm[j] > perm[i]
    int j = k - 1;
    while (perm[j] <= perm[i]) {
        j--;
    }

    // Swap perm[i] and perm[j]
    swap(&perm[i], &perm[j]);

    // Reverse the subarray perm[i+1..k-1]
    int l = i + 1;
    int r = k - 1;
    while (l < r) {
        swap(&perm[l], &perm[r]);
        l++;
        r--;
    }

    return 1;
}

int main() {
    int perm[] = {0, 1, 2};
    int k = 3;
    int n = 3;
    int count = 0;

    do {
        for (int i = 0; i < k - 1; i++) {
            printf("%d, ", perm[i]);
        }
        printf("%d\n", perm[k - 1]);
        count++;
    } while (next_permutation(perm, k, n));

    printf("Total permutations: %d\n", count);

    return 0;
}
