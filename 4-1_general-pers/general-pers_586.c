#include <stdio.h>
#include <stdbool.h>

int next_permutation(int perm[], int k, int n) {
    int i = k - 1;
    
    // Find the largest index i such that perm[i] < perm[i+1]
    while (i >= 0 && perm[i] == n - k + i) {
        i--;
    }
    
    if (i == -1) {
        return 0;  // All permutations generated
    }
    
    // Find the smallest perm[j] such that perm[j] > perm[i]
    int j = k - 1;
    while (perm[j] <= perm[i]) {
        j--;
    }
    
    // Swap perm[i] and perm[j]
    int temp = perm[i];
    perm[i] = perm[j];
    perm[j] = temp;
    
    // Reverse the elements to the right of i
    int left = i + 1, right = k - 1;
    while (left < right) {
        temp = perm[left];
        perm[left] = perm[right];
        perm[right] = temp;
        left++;
        right--;
    }
    
    return 1;  // Permutation generated successfully
}

int main() {
    int k = 2;  // Permutation length
    int n = 4;  // Range of elements

    int perm[2] = { 0, 1 };  // Starting permutation
    
    unsigned long long count = 0;
    
    do {
        for (int i = 0; i < k - 1; i++) {
            printf("%d, ", perm[i]);
        }
        printf("%d\n", perm[k - 1]);
        
        count++;
    } while (next_permutation(perm, k, n));
    
    printf("\nTotal permutations: %llu\n", count);
    
    return 0;
}
