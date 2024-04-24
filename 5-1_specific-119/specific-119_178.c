#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to swap two elements in an array
void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Recursive function to perform the operation described
int DoThisRecursive(int n, int arr[n], int target[n], int level) {
    if (memcmp(arr, target, n * sizeof(int)) == 0) {
        return level;
    }

    int *copy = malloc(n * sizeof(int));
    memcpy(copy, arr, n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        swap(copy, i, j);
        int result = DoThisRecursive(n, copy, target, level + 1);
        if (result != -1) {
            free(copy);
            return result;
        }
        swap(copy, i, j); // Swap back to original for next iteration
    }
    
    free(copy);
    return -1;
}

// Initial call to the recursive function
int FindTargetLevel(int n, int arr[n], int target[n]) {
    return DoThisRecursive(n, arr, target, 1);
}

int main() {
    int a[] = {2, 3, 4, 1};
    int b[] = {1, 2, 4, 3};
    
    int level = FindTargetLevel(4, a, b);
    
    if (level != -1) {
        printf("Desired array found at level: %d\n", level);
    } else {
        printf("Desired array not found\n");
    }
    
    return 0;
}
