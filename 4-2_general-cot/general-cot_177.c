#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare_arrays(int n, int arr1[n], int arr2[n]) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return 0; // Arrays are not equal
        }
    }
    return 1; // Arrays are equal
}

int **DoThis(int n, int arr[n]) {
    int l = n;
    int **b = malloc(l * sizeof(*b));
    int i, j, k;
    for (i = 0; i < l; i++) {
        j = (i + 1) % l;
        int *copy = malloc(l * sizeof(*copy));
        for (k = 0; k < l; k++)
            copy[k] = arr[k];
        int t = copy[i];
        copy[i] = copy[j];
        copy[j] = t;
        b[i] = copy;
    }
    return b;
}

int findLevel(int n, int **arr, int target[]) {
    int level = 1;
    while (1) {
        for (int i = 0; i < n; i++) {
            if (compare_arrays(n, arr[i], target)) {
                return level;
            }
        }
        
        int **new_arr = malloc(n * sizeof(*new_arr));
        for (int i = 0; i < n; i++) {
            new_arr[i] = *DoThis(n, arr[i]);
        }

        for (int i = 0; i < n; i++) {
            free(arr[i]);
        }
        free(arr);
        arr = new_arr;
        
        level++;
    }
}

int main() {
    int a[] = {2, 3, 4, 1};
    int b[] = {1, 2, 4, 3};
    int **initial_arr = DoThis(4, a);
    int target[] = {1, 2, 4, 3};

    int level = findLevel(4, initial_arr, target);
    printf("Target found at level: %d \n", level);

    return 0;
}
