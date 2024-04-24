#include <stdlib.h> 
#include <stdio.h> 

void merge(int arr[], int l, int m, int r) 
{
    // Your existing merge function remains unchanged
}

void mergeSort(int arr[], int l, int r) 
{
    if (l < r) 
    { 
        int m = l + (r - l) / 2; 

        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 

        merge(arr, l, m, r);

        // Print the array after each merge step
        printf("Array after merging from %d to %d: ", l, r);
        for (int i = l; i <= r; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } 
}

void printArray(int A[], int size) 
{ 
    // Your existing printArray function remains unchanged
}

int main() 
{ 
    int arr[20];
    int i, n;
    
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printArray(arr, n); 
    mergeSort(arr, 0, n - 1); 
    
    printf("\nSorted array is \n"); 
    printArray(arr, n); 
    
    return 0; 
} 
