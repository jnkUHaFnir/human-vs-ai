#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void permute(int *array, int start, int end, int k) {
    int i;
    if (start == k) { // When k elements are fixed, print them
        for (i = 0; i < k; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    } else {
        for (i = start; i < end; i++) {
            swap((array+start), (array+i));
            permute(array, start+1, end, k);
            swap((array+start), (array+i)); // backtrack
        }
    }
}

int main() {
    int n = 4;
    int k = 2;
    int *array = (int*)malloc(n * sizeof(int));
    
    // Initialize array with the range [0,n-1]
    for (int i = 0; i < n; i++) {
        array[i] = i;
    }
    
    // Generate permutations
    permute(array, 0, n, k);
    
    free(array);
    return 0;
}
