#include <stdio.h>

int nextPerm(int perm[], int k, int n) {
    int i = k - 1, j = k - 1;
    
    // Find the largest index i such that perm[i] < perm[i+1]
    while (i > 0 && perm[i - 1] >= perm[i]) {
        i--;
    }
    
    if (i <= 0) {
        return 0; // Last permutation reached
    }
    
    // Find the largest index j greater than i such that perm[j] > perm[i-1]
    while (perm[j] <= perm[i - 1]) {
        j--;
    }
    
    // Swap perm[i-1] and perm[j]
    int temp = perm[i - 1];
    perm[i - 1] = perm[j];
    perm[j] = temp;
    
    // Reverse the suffix starting at perm[i]
    j = k - 1;
    while (i < j) {
        temp = perm[i];
        perm[i] = perm[j];
        perm[j] = temp;
        i++;
        j--;
    }
    
    return 1; // Next permutation found successfully
}

int main() {
    int k = 2; // Length of permutation
    int n = 4; // Range of values
    int perm[2] = {0, 1}; // Initial permutation
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
