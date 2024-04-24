#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool compareArrays(int n, int arr1[n], int arr2[n]) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

int findLevel(int n, int arr[n], int target[], int level) {
    if (compareArrays(n, arr, target)) {
        return level;
    }
    
    int **output = DoThis(n, arr);
    for (int i = 0; i < n; i++) {
        int result = findLevel(n, output[i], target, level + 1);
        if (result != -1) {
            return result;
        }
    }
    
    for (int i = 0; i < n; i++) {
        free(output[i]);
    }
    free(output);
    
    return -1;
}

int main() {
    int a[] = {2, 3, 4, 1};
    int b[] = {1, 2, 4, 3};
    int target[] = {1, 2, 4, 3};
    
    int level = findLevel(4, a, target, 1);
    
    if (level != -1) {
        printf("Found target array at level %d\n", level);
    } else {
        printf("Target array not found\n");
    }
    
    return 0;
}
