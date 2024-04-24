#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to swap two elements in an integer array
void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to check if two integer arrays are equal
int arraysEqual(int *arr1, int *arr2, int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
    return 1;
}

// Recursive function to perform the required operations
int DoThisRecursively(int n, int *arr, int *target, int level) {
    if (arraysEqual(arr, target, n)) {
        return level;
    }
    
    int *copy = malloc(n * sizeof(*copy));
    if (copy == NULL) {
        // Handle memory allocation failure
        return -1;
    }
    
    memcpy(copy, arr, n * sizeof(*copy));

    int **b = malloc(n * sizeof(*b));
    if (b == NULL) {
        // Handle memory allocation failure
        free(copy);
        return -1;
    }

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        swap(copy, i, j);

        b[i] = malloc(n * sizeof(*b[i]));
        if (b[i] == NULL) {
            // Handle memory allocation failure
            for (int k = 0; k < i; k++) {
                free(b[k]);
            }
            free(b);
            free(copy);
            return -1;
        }

        memcpy(b[i], copy, n * sizeof(*b[i]));
        int result = DoThisRecursively(n, copy, target, level + 1);

        for (int k = 0; k <= i; k++) {
            free(b[k]);
        }

        if (result != -1) {
            free(b);
            free(copy);
            return result;
        }
    }

    free(b);
    free(copy);
    return -1;
}

// Wrapper function to initialize the recursion
int DoThis(int n, int arr[n]) {
    int *target = malloc(n * sizeof(*target));
    if (target == NULL) {
        // Handle memory allocation failure
        return -1;
    }

    for (int i = 0; i < n; i++) {
        target[i] = i + 1;
    }

    int level = DoThisRecursively(n, arr, target, 1);

    free(target);

    return level;
}

int main() {
    int a[] = {2, 3, 4, 1};
    int b[] = {1, 2, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);

    int result = DoThis(n, b);
    if (result == -1) {
        printf("An error occurred.\n");
    } else {
        printf("Result: %d\n", result);
    }

    return 0;
}
