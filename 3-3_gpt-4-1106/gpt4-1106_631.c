#include <stdio.h>

int main() {
    int n, j, k, item;
    printf("Enter size of array:\n");
    scanf("%d", &n);
    
    // Corrected: the array will have size n, so the max index is n-1
    int a[n];
    
    for (j = 0; j < n; j++) {
        printf("Enter a[%d] element:\n", j);
        scanf("%d", &a[j]);
    }
    
    printf("Enter element to insert and position of element (start from 1):\n");
    scanf("%d %d", &item, &k);
    
    // Validation for k to be within array bounds
    if(k < 1 || k > n + 1) {
        printf("Position is out of bounds.\n");
        return 1;
    }

    // Changed: Only shift if there's space to insert the new item.
    if(k <= n) {
        for(j = n - 1; j >= k - 1; j--) {
            a[j + 1] = a[j];
        }
        a[k - 1] = item;
    }

    // Print the array up to the index n-1 since we can't increase array size
    // If an element was inserted, the last element is dropped to keep array size consistent
    for(j = 0; j < n; j++) {
        printf("%d\n", a[j]);
    }

    return 0;
}
