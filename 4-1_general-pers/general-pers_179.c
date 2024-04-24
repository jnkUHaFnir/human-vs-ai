#include <stdio.h>
#include <stdlib.h>

int isEqualArrays(int n, int arr1[n], int arr2[n]) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
    return 1;
}

int **DoThis(int n, int arr[n]) {
    int l = n;
    int **b = malloc(l * sizeof(*b));

    if (!b) {
        // Handle memory allocation failure
        return NULL;
    }

    for (int i = 0; i < l; i++) {
        int *copy = malloc(l * sizeof(*copy));
        if (!copy) {
            // Handle memory allocation failure
            for (int k = 0; k < i; k++) {
                free(b[k]); // Free previously allocated memory
            }
            free(b);
            return NULL;
        }
        
        for (int k = 0; k < l; k++) {
            copy[k] = arr[k];
        }

        int j = (i + 1) % l;
        int t = copy[i];
        copy[i] = copy[j];
        copy[j] = t;

        b[i] = copy;
    }

    return b;
}

int main() {
    int a[] = {2, 3, 4, 1};
    int b[] = {1, 2, 4, 3};

    int **result = NULL;
    int level = 0;
    
    int n = sizeof(a) / sizeof(a[0]);

    while (!isEqualArrays(n, a, b)) {
        result = DoThis(n, a);

        if (!result) {
            // Handle error
            printf("Error: Memory allocation failed.\n");
            break;
        }

        // Update the input array 'a' with the first array in the result
        for (int i = 0; i < n; i++) {
            a[i] = result[0][i];
        }

        level++;
        
        // Free memory for result
        for (int i = 0; i < n; i++) {
            free(result[i]);
        }
        free(result);
    }

    printf("Result: %d\n", level);

    return 0;
}
