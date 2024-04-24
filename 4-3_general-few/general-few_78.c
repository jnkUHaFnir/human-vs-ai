#include <stdio.h>

int nextPermutation(int perm[], int k, int n) {
    int i = k - 1;
    
    while (i >= 0 && perm[i] == n - k + i) {
        i--;
    }
    
    if (i < 0) {
        return 0; // All permutations generated
    }
    
    perm[i]++;
    
    for (int j = i + 1; j < k; j++) {
        perm[j] = perm[j - 1] + 1;
    }
    
    return 1;
}

int main() {
    int k = 3;
    int n = 10;
    int perm[3] = {0, 1, 2}; // Initial permutation
    unsigned long long count = 0;

    do {
        for (int i = 0; i < k - 1; i++) {
            printf("%d, ", perm[i]);
        }
        printf("%d\n", perm[k - 1]);
        
        count++;
    } while (nextPermutation(perm, k, n));
    
    printf("\nTotal permutations: %llu\n", count);

    return 0;
}
