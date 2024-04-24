void printArraySubset(int A[], int start, int end) 
{ 
    int i; 
    for (i = start; i <= end; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
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

    // Intermediate prints
    int m = n / 2; // Middle index

    // Print elements before m
    printArraySubset(arr, 0, m - 1);

    // Print elements after m
    printArraySubset(arr, m, n - 1);

    mergeSort(arr, 0, n - 1); 
    printf("\nSorted array is \n"); 
    printArray(arr, n); 

    return 0; 
} 
