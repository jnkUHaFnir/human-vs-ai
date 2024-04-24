#include <stdlib.h>
#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    // Merge function remains the same
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        printf("\nMerging: ");
        for (int i = l; i <= r; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        merge(arr, l, m, r);

        printf("After merging: ");
        for (int i = l; i <= r; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void printArray(int A[], int size)
{
    // printArray function remains the same
}

int main()
{
    int arr[20];
    int i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    printf("\nSorted array is \n");
    printArray(arr, n);
    return 0;
}
