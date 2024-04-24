#include <stdlib.h>
#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    // Your existing merge function implementation remains the same
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);

        // Print partially sorted array at each stage
        printf("\nPartially Sorted array is \n");
        printArray(arr, r + 1);
    }
}

void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int arr[20];
    int i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nInitial array is \n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("\nSorted array is \n");
    printArray(arr, n);

    return 0;
}
