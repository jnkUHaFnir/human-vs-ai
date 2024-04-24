#include <stdio.h>

int next_permutation(int perm[], int k, int n) {
    int i = k - 1;
    
    // Find the rightmost element that has not reached its maximum value
    while (i >= 0 && perm[i] == (n - k + i)) {
        i--;
    }
    
    // If no such element is found, the current permutation is the last one
    if (i == -1) {
        return 0;
    }
    
    // Increment the rightmost element that has not reached its maximum value
    perm[i]++;
    
    // Adjust the elements to the right of this element
    for (int j = i + 1; j < k; j++) {
        perm[j] = perm[j - 1] + 1;
    }
    
    return 1;
}

int main() {
    int k = 3; // Elements in each permutation
    int n = 10; // Total elements available
    int count = 0;
    
    int perm[3] = {0, 1, 2}; // Starting permutation
    
    do {
        for (int i = 0; i < k - 1; i++) {
            printf("%d, ", perm[i]);
        }
        printf("%d\n", perm[k - 1]);
        
        count++;
    } while (next_permutation(perm, k, n));
    
    printf("\nTotal permutations: %d\n", count);
    
    return 0;
}
