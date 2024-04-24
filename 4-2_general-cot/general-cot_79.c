#include <stdio.h>

int nextPerm(int perm[], int k, int n) {
    // Find the largest index i such that perm[i] < perm[i+1]
    int i = k - 2;
    while (i >= 0 && perm[i] >= perm[i + 1]) {
        i--;
    }

    // If no such index exists, the permutation is the last one
    if (i < 0) {
        return 0;
    }

    // Find the largest index j greater than i such that perm[i] < perm[j]
    int j = k - 1;
    while (perm[j] <= perm[i]) {
        j--;
    }

    // Swap elements at indices i and j
    int temp = perm[i];
    perm[i] = perm[j];
    perm[j] = temp;

    // Reverse the elements from i+1 to the end
    int left = i + 1, right = k - 1;
    while (left < right) {
        temp = perm[left];
        perm[left] = perm[right];
        perm[right] = temp;
        left++;
        right--;
    }

    return 1;
}

int main() {
    int k = 3, n = 4;
    int perm[3] = {0, 1, 2}; // Starting permutation
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
