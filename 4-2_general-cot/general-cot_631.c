#include<stdio.h>

int main() {
    int n, j, k, item;
    
    printf("Enter size of array:\n");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("Array size should be a positive integer.\n");
        return 1;
    }
    
    printf("Enter element to insert and position of element:\n");
    scanf("%d, %d", &item, &k);
    
    if(k < 1 || k > n+1) {
        printf("Invalid position to insert element.\n");
        return 1;
    }
    
    int a[n+1]; // Increase the array size by 1 to accommodate the new element

    for (j = 0; j < n; j++) {
        printf("Enter a[%d] element:\n", j);
        scanf("%d", &a[j]);
    }
    
    // Shift elements to the right to make space for the new element
    for (j = n; j >= k; j--) {
        a[j] = a[j - 1];
    }
    
    a[k - 1] = item;
    
    // Print the updated array
    for (j = 0; j < n + 1; j++) {
        printf("%d\n", a[j]);
    }

    return 0;
}
